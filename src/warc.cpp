#include "warc.h"

#include <charconv>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string_view>
#include <utility>

warc::Record::Record() {}

// removeAngleBrackets removes leading and trailing angle brackets.
// "<x>" -> "x"
// "x" -> "x"
constexpr std::string_view removeAngleBrackets(std::string_view s) {
    if (s.starts_with("<") && s.ends_with(">")) {
        s.remove_prefix(1);
        s.remove_suffix(1);
    }
    return s;
}

std::pair<warc::error::Error, size_t> warc::Record::parse(const std::string_view data, bool strict) noexcept {
    /*
    CR            = <ASCII CR, carriage return>  ; (13)
    LF            = <ASCII LF, linefeed>         ; (10)
    SP            = <ASCII SP, space>            ; (32)
    HT            = <ASCII HT, horizontal-tab>   ; (9)
    CRLF          = CR LF
    LWS           = [CRLF] 1*( SP | HT )         ; semantics same as
    */

    // remove leading linear whitespace
    constexpr std::string_view kLWS = " \r\n\t";
    const auto start_pos = data.find_first_not_of(kLWS);
    if (start_pos == std::string_view::npos) {
        return {warc::error::Error::kOther, 0};
    }
    size_t consumed = start_pos;

    // header       = version warc-fields
    // version
    constexpr std::string_view kWarcPrefix = "WARC/1.";
    if (data.find(kWarcPrefix, consumed) != consumed) {
        return {warc::error::Error::kInvalidPrefix, consumed};
    }
    consumed += kWarcPrefix.size();

    // allow WARC 1.0 or 1.1
    if (data.find_first_of("01", consumed) != consumed) {
        return {warc::error::Error::kInvalidPrefix, consumed};
    }
    consumed += 1;

    constexpr std::string_view kCRLF = "\r\n";
    if (data.find(kCRLF, consumed) != consumed) {
        return {warc::error::Error::kInvalidPrefix, consumed};
    }
    consumed += kCRLF.size();

    // warc-fields
    while (true) {
        const auto next_line_end = data.find(kCRLF, consumed);
        if (next_line_end == std::string_view::npos) {
            return {warc::error::Error::kInvalidHeader, consumed};
        }

        const auto line = data.substr(consumed, next_line_end - consumed);
        if (line.empty()) {
            // end of headers
            consumed += kCRLF.size();
            break;
        }

        // Each named field consists of a name followed by a colon (“:”) and
        // the field value.... The field value may be preceded by any amount
        // of linear white space (LWS), though a single space is preferred.
        // Not supported: "Header fields can be extended over multiple lines
        // by preceding each extra line with at least one space or tab
        // character"
        const auto colon_pos = line.find(':');
        if (colon_pos == std::string_view::npos) {
            return {warc::error::Error::kInvalidHeader, consumed};
        }
        const auto value_pos = line.find_first_not_of(kLWS, colon_pos + 1);
        if (value_pos == std::string_view::npos) {
            return {warc::error::Error::kInvalidHeader, consumed};
        }

        const auto key = line.substr(0, colon_pos);
        const auto value = line.substr(value_pos);

        const auto field = warc::field::fromString(key);
        switch (field) {
            case warc::field::Field::kWarcRecordID: {
                // WARC-Record-ID   = "WARC-Record-ID" ":" "<" uri ">"
                warcRecordID_ = {removeAngleBrackets(value), true};
                break;
            }
            case warc::field::Field::kContentLength: {
                // Content-Length   = "Content-Length" ":" 1*DIGIT
                const auto result = std::from_chars(value.data(), value.data() + value.size(), contentLength_.first);
                if (result.ec == std::errc::invalid_argument || result.ec == std::errc::result_out_of_range) {
                    return {warc::error::Error::kInvalidInteger, consumed};
                }
                contentLength_.second = true;
                break;
            }
            case warc::field::Field::kWarcDate: {
                // WARC-Date = "WARC-Date" ":" w3c-iso8601
                // w3c-iso8601 = <a UTC timestamp formatted according to [W3CDTF]>
                // TODO: parse date
                warcDate_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcType: {
                // WARC-Type   = "WARC-Type" ":" record-type
                const record_type::RecordType type = warc::record_type::fromString(value);
                if (type == warc::record_type::RecordType::kInvalid) {
                    return {warc::error::Error::kInvalidResponseType, consumed};
                }
                warcType_ = {type, true};
                break;
            }
            case warc::field::Field::kContentType: {
                // Content-Type  = "Content-Type" ":" media-type
                contentType_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcConcurrentTo: {
                // WARC-Concurrent-To = "WARC-Concurrent-To" ":" "<" uri ">"
                warcConcurrentTo_ = {removeAngleBrackets(value), true};
                break;
            }
            case warc::field::Field::kWarcBlockDigest: {
                // WARC-Block-Digest = "WARC-Block-Digest" ":" labelled-digest
                // labelled-digest   = algorithm ":" digest-value
                // algorithm         = token
                // digest-value      = token
                warcBlockDigest_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcPayloadDigest: {
                // WARC-Payload-Digest = "WARC-Payload-Digest" ":" labelled-digest
                warcPayloadDigest_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcIPAddress: {
                // WARC-IP-Address = "WARC-IP-Address" ":" (ipv4 | ipv6)
                // ipv4            = <"dotted quad">
                // ipv6            = <per section 2.2 of RFC4291>
                warcIPAddress_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcRefersTo: {
                // WARC-Refers-To  = "WARC-Refers-To" ":" "<" uri ">"
                warcRefersTo_ = {removeAngleBrackets(value), true};
                break;
            }
            case warc::field::Field::kWarcRefersToTargetURI: {
                // WARC-Refers-To-Target-URI = "WARC-Refers-To-Target-URI" ":" uri
                warcRefersToTargetURI_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcRefersToDate: {
                // WARC-Refers-To-Date = "WARC-Refers-To-Date" ":" w3c-iso8601
                // TODO: parse date
                warcRefersToDate_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcTargetURI: {
                // WARC-Target-URI    = "WARC-Target-URI" ":" uri
                // Community recommendation: Readers should remove enclosing “<” and “>” characters from the WARC-Target-URI field value if present before processing the URI.
                warcTargetURI_ = {removeAngleBrackets(value), true};
                break;
            }
            case warc::field::Field::kWarcTruncated: {
                // WARC-Truncated = "WARC-Truncated" ":" reason-token
                const warc::truncated_reason::TruncatedReason reason = warc::truncated_reason::fromString(value);
                if (reason == warc::truncated_reason::TruncatedReason::kInvalid) {
                    return {warc::error::Error::kInvalidTruncatedReason, consumed};
                }
                warcTruncated_ = {reason, true};
                break;
            }
            case warc::field::Field::kWarcWarcinfoID: {
                // WARC-Warcinfo-ID = "WARC-Warcinfo-ID" ":" "<" uri ">"
                warcWarcinfoID_ = {removeAngleBrackets(value), true};
                break;
            }
            case warc::field::Field::kWarcFilename: {
                // WARC-Filename = "WARC-Filename" ":" ( TEXT | quoted-string )
                warcFilename_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcProfile: {
                // WARC-Profile = "WARC-Profile" ":" uri
                // Community recommendation: Readers should remove enclosing “<” and “>” characters from the WARC-Profile field value if present before processing the URI.
                warcProfile_ = {removeAngleBrackets(value), true};
                break;
            }
            case warc::field::Field::kWarcIdentifiedPayloadType: {
                // WARC-Identified-Payload-Type = "WARC-Identified-Payload-Type" ":" media-type
                warcIdentifiedPayloadType_ = {value, true};
                break;
            }
            case warc::field::Field::kWarcSegmentNumber: {
                // WARC-Segment-Number = "WARC-Segment-Number" ":" 1*DIGIT
                const auto result = std::from_chars(value.data(), value.data() + value.size(), warcSegmentNumber_.first);
                if (result.ec == std::errc::invalid_argument || result.ec == std::errc::result_out_of_range) {
                    return {warc::error::Error::kInvalidInteger, consumed};
                }
                warcSegmentNumber_.second = true;
                break;
            }
            case warc::field::Field::kWarcSegmentOriginID: {
                // WARC-Segment-Origin-ID = "WARC-Segment-Origin-ID" ":" "<" uri ">"
                warcSegmentOriginID_ = {removeAngleBrackets(value), true};
                break;
            }
            case warc::field::Field::kWarcSegmentTotalLength: {
                // WARC-Segment-Total-Length = "WARC-Segment-Total-Length" ":" 1*DIGIT
                const auto result = std::from_chars(value.data(), value.data() + value.size(), warcSegmentTotalLength_.first);
                if (result.ec == std::errc::invalid_argument || result.ec == std::errc::result_out_of_range) {
                    return {warc::error::Error::kInvalidInteger, consumed};
                }
                warcSegmentTotalLength_.second = true;
                break;
            }
            case warc::field::Field::kWarcProtocol: {
                // "WARC-Protocol" ":" protocol-id
                const warc::protocol::Protocol protocol = warc::protocol::fromString(value);
                if (protocol == warc::protocol::Protocol::kInvalid) {
                    return {warc::error::Error::kInvalidProtocol, consumed};
                }
                warcProtocol_ = {protocol, true};
                break;
            }
            default: {
                if (strict) {
                    return {warc::error::Error::kInvalidField, consumed};
                } else {
                    // std::cout << "Unsupported field: " << key << std::endl;
                    break;
                }
            }
        }

        consumed = next_line_end + kCRLF.size();
    }

    // WARC-Record-ID (mandatory)
    // Content-Length (mandatory)
    // WARC-Date (mandatory)
    // WARC-Type (mandatory)
    if (!warcRecordID().second || !contentLength().second || !warcDate().second || !warcType().second) {
        return {warc::error::Error ::kMissingMandatoryField, consumed};
    }
    const auto length = contentLength().first;
    if (data.size() < (consumed + length)) {
        return {warc::error::Error::kInvalidContentLength, consumed};
    }
    rawBody_ = {data.substr(consumed, contentLength().first), true};
    consumed += contentLength().first;

    return {warc::error::Error::kSuccess, consumed};
}
