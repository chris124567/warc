#include "warc.h"

std::string_view warc::error::toString(warc::error::Error error) {
    switch (error) {
        case warc::error::Error::kSuccess:
            return "success";
        case warc::error::Error::kOther:
            return "other";
        case warc::error::Error::kInvalidPrefix:
            return "invalid_prefix";
        case warc::error::Error::kInvalidHeader:
            return "invalid_header";
        case warc::error::Error::kInvalidField:
            return "invalid_field";
        case warc::error::Error::kInvalidInteger:
            return "invalid_integer";
        case warc::error::Error::kInvalidResponseType:
            return "invalid_response_type";
        case warc::error::Error::kInvalidTruncatedReason:
            return "invalid_truncated_reason";
        case warc::error::Error::kMissingMandatoryField:
            return "missing_mandatory_field";
        case warc::error::Error::kInvalidContentLength:
            return "invalid_content_length";
        case warc::error::Error::kInvalidProtocol:
            return "invalid_protocol";
        default:
            return "invalid";
    }
}

warc::error::Error fromString(const std::string_view s) {
    if (s == "success") {
        return warc::error::Error::kSuccess;
    } else if (s == "other") {
        return warc::error::Error::kOther;
    } else if (s == "invalid_prefix") {
        return warc::error::Error::kInvalidPrefix;
    } else if (s == "invalid_header") {
        return warc::error::Error::kInvalidHeader;
    } else if (s == "invalid_field") {
        return warc::error::Error::kInvalidField;
    } else if (s == "invalid_integer") {
        return warc::error::Error::kInvalidInteger;
    } else if (s == "invalid_response_type") {
        return warc::error::Error::kInvalidResponseType;
    } else if (s == "invalid_truncated_reason") {
        return warc::error::Error::kInvalidTruncatedReason;
    } else if (s == "missing_mandatory_field") {
        return warc::error::Error::kMissingMandatoryField;
    } else if (s == "invalid_content_length") {
        return warc::error::Error::kInvalidContentLength;
    } else if (s == "invalid_protocol") {
        return warc::error::Error::kInvalidProtocol;
    }
    return warc::error::Error::kInvalid;
}

std::ostream& warc::error::operator<<(std::ostream& os, warc::error::Error err) {
    return os << warc::error::toString(err);
}

std::string_view warc::record_type::toString(record_type::RecordType type) {
    switch (type) {
        case record_type::RecordType::kWarcinfo:
            return "warcinfo";
        case record_type::RecordType::kResponse:
            return "response";
        case record_type::RecordType::kResource:
            return "resource";
        case record_type::RecordType::kRequest:
            return "request";
        case record_type::RecordType::kMetadata:
            return "metadata";
        case record_type::RecordType::kRevisit:
            return "revisit";
        case record_type::RecordType::kConversion:
            return "conversion";
        case record_type::RecordType::kContinuation:
            return "continuation";
        default:
            return "invalid";
    }
}

warc::record_type::RecordType warc::record_type::fromString(const std::string_view s) {
    if (s == "warcinfo") {
        return record_type::RecordType::kWarcinfo;
    } else if (s == "response") {
        return record_type::RecordType::kResponse;
    } else if (s == "resource") {
        return record_type::RecordType::kResource;
    } else if (s == "request") {
        return record_type::RecordType::kRequest;
    } else if (s == "metadata") {
        return record_type::RecordType::kMetadata;
    } else if (s == "revisit") {
        return record_type::RecordType::kRevisit;
    } else if (s == "conversion") {
        return record_type::RecordType::kConversion;
    } else if (s == "continuation") {
        return record_type::RecordType::kContinuation;
    }
    return RecordType::kInvalid;
}

std::ostream& warc::record_type::operator<<(std::ostream& os, warc::record_type::RecordType err) {
    return os << warc::record_type::toString(err);
}

std::string_view warc::truncated_reason::toString(warc::truncated_reason::TruncatedReason reason) {
    switch (reason) {
        case warc::truncated_reason::TruncatedReason::kLength:
            return "length";
        case warc::truncated_reason::TruncatedReason::kTime:
            return "time";
        case warc::truncated_reason::TruncatedReason::kDisconnect:
            return "disconnect";
        case warc::truncated_reason::TruncatedReason::kUnspecified:
            return "unspecified";
        default:
            return "invalid";
    }
}

warc::truncated_reason::TruncatedReason warc::truncated_reason::fromString(const std::string_view s) {
    if (s == "length") {
        return warc::truncated_reason::TruncatedReason::kLength;
    } else if (s == "time") {
        return warc::truncated_reason::TruncatedReason::kTime;
    } else if (s == "disconnect") {
        return warc::truncated_reason::TruncatedReason::kDisconnect;
    } else if (s == "unspecified") {
        return warc::truncated_reason::TruncatedReason::kUnspecified;
    }
    return warc::truncated_reason::TruncatedReason::kInvalid;
}

std::ostream& warc::truncated_reason::operator<<(std::ostream& os, warc::truncated_reason::TruncatedReason err) {
    return os << warc::truncated_reason::toString(err);
}

std::string_view warc::protocol::toString(warc::protocol::Protocol protocol) {
    switch (protocol) {
        case warc::protocol::Protocol::kDns:
            return "dns";
        case warc::protocol::Protocol::kFtp:
            return "ftp";
        case warc::protocol::Protocol::kGemini:
            return "gemini";
        case warc::protocol::Protocol::kGopher:
            return "gopher";
        case warc::protocol::Protocol::kHttp_0_9:
            return "http/0.9";
        case warc::protocol::Protocol::kHttp_1_0:
            return "http/1.0";
        case warc::protocol::Protocol::kHttp_1_1:
            return "http/1.1";
        case warc::protocol::Protocol::kH2:
            return "h2";
        case warc::protocol::Protocol::kH2c:
            return "h2c";
        case warc::protocol::Protocol::kH3:
            return "h3";
        case warc::protocol::Protocol::kQuic_1:
            return "quic/1";
        case warc::protocol::Protocol::kQuic_2:
            return "quic/2";
        case warc::protocol::Protocol::kSpdy_1:
            return "spdy/1";
        case warc::protocol::Protocol::kSpdy_2:
            return "spdy/2";
        case warc::protocol::Protocol::kSpdy_3:
            return "spdy/3";
        case warc::protocol::Protocol::kSsl_2:
            return "ssl/2";
        case warc::protocol::Protocol::kSsl_3:
            return "ssl/3";
        case warc::protocol::Protocol::kTls_1_0:
            return "tls/1.0";
        case warc::protocol::Protocol::kTls_1_1:
            return "tls/1.1";
        case warc::protocol::Protocol::kTls_1_2:
            return "tls/1.2";
        case warc::protocol::Protocol::kTls_1_3:
            return "tls/1.3";
        default:
            return "invalid";
    }
}

warc::protocol::Protocol warc::protocol::fromString(const std::string_view s) {
    if (s == "dns") {
        return warc::protocol::Protocol::kDns;
    } else if (s == "ftp") {
        return warc::protocol::Protocol::kFtp;
    } else if (s == "gemini") {
        return warc::protocol::Protocol::kGemini;
    } else if (s == "gopher") {
        return warc::protocol::Protocol::kGopher;
    } else if (s == "http/0.9") {
        return warc::protocol::Protocol::kHttp_0_9;
    } else if (s == "http/1.0") {
        return warc::protocol::Protocol::kHttp_1_0;
    } else if (s == "http/1.1") {
        return warc::protocol::Protocol::kHttp_1_1;
    } else if (s == "h2") {
        return warc::protocol::Protocol::kH2;
    } else if (s == "h2c") {
        return warc::protocol::Protocol::kH2c;
    } else if (s == "h3") {
        return warc::protocol::Protocol::kH3;
    } else if (s == "quic/1") {
        return warc::protocol::Protocol::kQuic_1;
    } else if (s == "quic/2") {
        return warc::protocol::Protocol::kQuic_2;
    } else if (s == "spdy/1") {
        return warc::protocol::Protocol::kSpdy_1;
    } else if (s == "spdy/2") {
        return warc::protocol::Protocol::kSpdy_2;
    } else if (s == "spdy/3") {
        return warc::protocol::Protocol::kSpdy_3;
    } else if (s == "ssl/2") {
        return warc::protocol::Protocol::kSsl_2;
    } else if (s == "ssl/3") {
        return warc::protocol::Protocol::kSsl_3;
    } else if (s == "tls/1.0") {
        return warc::protocol::Protocol::kTls_1_0;
    } else if (s == "tls/1.1") {
        return warc::protocol::Protocol::kTls_1_1;
    } else if (s == "tls/1.2") {
        return warc::protocol::Protocol::kTls_1_2;
    } else if (s == "tls/1.3") {
        return warc::protocol::Protocol::kTls_1_3;
    }
    return warc::protocol::Protocol::kInvalid;
}

std::ostream& operator<<(std::ostream& os, warc::protocol::Protocol protocol) {
    return os << warc::protocol::toString(protocol);
}

std::string_view warc::field::toString(warc::field::Field field) {
    switch (field) {
        case Field::kWarcRecordID:
            return "WARC-Record-ID";
        case Field::kContentLength:
            return "Content-Length";
        case Field::kWarcDate:
            return "WARC-Date";
        case Field::kWarcType:
            return "WARC-Type";
        case Field::kContentType:
            return "Content-Type";
        case Field::kWarcConcurrentTo:
            return "WARC-Concurrent-To";
        case Field::kWarcBlockDigest:
            return "WARC-Block-Digest";
        case Field::kWarcPayloadDigest:
            return "WARC-Payload-Digest";
        case Field::kWarcIPAddress:
            return "WARC-IP-Address";
        case Field::kWarcRefersTo:
            return "WARC-Refers-To";
        case Field::kWarcRefersToTargetURI:
            return "WARC-Refers-To-Target-URI";
        case Field::kWarcRefersToDate:
            return "WARC-Refers-To-Date";
        case Field::kWarcTargetURI:
            return "WARC-Target-URI";
        case Field::kWarcTruncated:
            return "WARC-Truncated";
        case Field::kWarcWarcinfoID:
            return "WARC-Warcinfo-ID";
        case Field::kWarcFilename:
            return "WARC-Filename";
        case Field::kWarcProfile:
            return "WARC-Profile";
        case Field::kWarcIdentifiedPayloadType:
            return "WARC-Identified-Payload-Type";
        case Field::kWarcSegmentNumber:
            return "WARC-Segment-Number";
        case Field::kWarcSegmentOriginID:
            return "WARC-Segment-Origin-ID";
        case Field::kWarcSegmentTotalLength:
            return "WARC-Segment-Total-Length";
        case Field::kWarcProtocol:
            return "WARC-Protocol";
        default:
            return "Invalid";
    }
}

// caseInsensitiveEqual compares two strings for equality ignoring case.
constexpr bool caseInsensitiveEqual(const std::string_view s1, const std::string_view s2) {
    return std::equal(s1.begin(), s1.end(), s2.begin(), s2.end(), [](const char c1, const char c2) {
        return std::tolower(c1) == std::tolower(c2);
    });
}

// Field names are not case-sensitive.
// https://iipc.github.io/warc-specifications/specifications/warc-format/warc-1.1-annotated/#file-and-record-model
warc::field::Field warc::field::fromString(const std::string_view s) {
    if (caseInsensitiveEqual(s, "WARC-Record-ID")) {
        return warc::field::Field::kWarcRecordID;
    } else if (caseInsensitiveEqual(s, "Content-Length")) {
        return warc::field::Field::kContentLength;
    } else if (caseInsensitiveEqual(s, "WARC-Date")) {
        return warc::field::Field::kWarcDate;
    } else if (caseInsensitiveEqual(s, "WARC-Type")) {
        return warc::field::Field::kWarcType;
    } else if (caseInsensitiveEqual(s, "Content-Type")) {
        return warc::field::Field::kContentType;
    } else if (caseInsensitiveEqual(s, "WARC-Concurrent-To")) {
        return warc::field::Field::kWarcConcurrentTo;
    } else if (caseInsensitiveEqual(s, "WARC-Block-Digest")) {
        return warc::field::Field::kWarcBlockDigest;
    } else if (caseInsensitiveEqual(s, "WARC-Payload-Digest")) {
        return warc::field::Field::kWarcPayloadDigest;
    } else if (caseInsensitiveEqual(s, "WARC-IP-Address")) {
        return warc::field::Field::kWarcIPAddress;
    } else if (caseInsensitiveEqual(s, "WARC-Refers-To")) {
        return warc::field::Field::kWarcRefersTo;
    } else if (caseInsensitiveEqual(s, "WARC-Refers-To-Target-URI")) {
        return warc::field::Field::kWarcRefersToTargetURI;
    } else if (caseInsensitiveEqual(s, "WARC-Refers-To-Date")) {
        return warc::field::Field::kWarcRefersToDate;
    } else if (caseInsensitiveEqual(s, "WARC-Target-URI")) {
        return warc::field::Field::kWarcTargetURI;
    } else if (caseInsensitiveEqual(s, "WARC-Truncated")) {
        return warc::field::Field::kWarcTruncated;
    } else if (caseInsensitiveEqual(s, "WARC-Warcinfo-ID")) {
        return warc::field::Field::kWarcWarcinfoID;
    } else if (caseInsensitiveEqual(s, "WARC-Filename")) {
        return warc::field::Field::kWarcFilename;
    } else if (caseInsensitiveEqual(s, "WARC-Profile")) {
        return warc::field::Field::kWarcProfile;
    } else if (caseInsensitiveEqual(s, "WARC-Identified-Payload-Type")) {
        return warc::field::Field::kWarcIdentifiedPayloadType;
    } else if (caseInsensitiveEqual(s, "WARC-Segment-Number")) {
        return warc::field::Field::kWarcSegmentNumber;
    } else if (caseInsensitiveEqual(s, "WARC-Segment-Origin-ID")) {
        return warc::field::Field::kWarcSegmentOriginID;
    } else if (caseInsensitiveEqual(s, "WARC-Segment-Total-Length")) {
        return warc::field::Field::kWarcSegmentTotalLength;
    } else if (caseInsensitiveEqual(s, "WARC-Protocol")) {
        return warc::field::Field::kWarcProtocol;
    } else {
        return warc::field::Field::kInvalid;
    }
}

std::ostream& warc::field::operator<<(std::ostream& os, warc::field::Field field) {
    return os << warc::field::toString(field);
}
