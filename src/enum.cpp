#include "warc.h"

std::string_view warc::error::toString(Error error) {
    switch (error) {
        case Error::kSuccess:
            return "success";
        case Error::kOther:
            return "other";
        case Error::kInvalidPrefix:
            return "invalid_prefix";
        case Error::kInvalidHeader:
            return "invalid_header";
        case Error::kInvalidField:
            return "invalid_field";
        case Error::kInvalidInteger:
            return "invalid_integer";
        case Error::kInvalidResponseType:
            return "invalid_response_type";
        case Error::kInvalidTruncatedReason:
            return "invalid_truncated_reason";
        case Error::kMissingMandatoryField:
            return "missing_mandatory_field";
        case Error::kInvalidContentLength:
            return "invalid_content_length";
        case Error::kInvalidProtocol:
            return "invalid_protocol";
        default:
            return "invalid";
    }
}

warc::error::Error warc::error::fromString(const std::string_view s) {
    if (s == "success") {
        return Error::kSuccess;
    } else if (s == "other") {
        return Error::kOther;
    } else if (s == "invalid_prefix") {
        return Error::kInvalidPrefix;
    } else if (s == "invalid_header") {
        return Error::kInvalidHeader;
    } else if (s == "invalid_field") {
        return Error::kInvalidField;
    } else if (s == "invalid_integer") {
        return Error::kInvalidInteger;
    } else if (s == "invalid_response_type") {
        return Error::kInvalidResponseType;
    } else if (s == "invalid_truncated_reason") {
        return Error::kInvalidTruncatedReason;
    } else if (s == "missing_mandatory_field") {
        return Error::kMissingMandatoryField;
    } else if (s == "invalid_content_length") {
        return Error::kInvalidContentLength;
    } else if (s == "invalid_protocol") {
        return Error::kInvalidProtocol;
    }
    return Error::kInvalid;
}

std::ostream& warc::error::operator<<(std::ostream& os, Error err) {
    return os << toString(err);
}

std::string_view warc::record_type::toString(RecordType type) {
    switch (type) {
        case RecordType::kWarcinfo:
            return "warcinfo";
        case RecordType::kResponse:
            return "response";
        case RecordType::kResource:
            return "resource";
        case RecordType::kRequest:
            return "request";
        case RecordType::kMetadata:
            return "metadata";
        case RecordType::kRevisit:
            return "revisit";
        case RecordType::kConversion:
            return "conversion";
        case RecordType::kContinuation:
            return "continuation";
        default:
            return "invalid";
    }
}

warc::record_type::RecordType warc::record_type::fromString(const std::string_view s) {
    if (s == "warcinfo") {
        return RecordType::kWarcinfo;
    } else if (s == "response") {
        return RecordType::kResponse;
    } else if (s == "resource") {
        return RecordType::kResource;
    } else if (s == "request") {
        return RecordType::kRequest;
    } else if (s == "metadata") {
        return RecordType::kMetadata;
    } else if (s == "revisit") {
        return RecordType::kRevisit;
    } else if (s == "conversion") {
        return RecordType::kConversion;
    } else if (s == "continuation") {
        return RecordType::kContinuation;
    }
    return RecordType::kInvalid;
}

std::ostream& warc::record_type::operator<<(std::ostream& os, RecordType err) {
    return os << toString(err);
}

std::string_view warc::truncated_reason::toString(TruncatedReason reason) {
    switch (reason) {
        case TruncatedReason::kLength:
            return "length";
        case TruncatedReason::kTime:
            return "time";
        case TruncatedReason::kDisconnect:
            return "disconnect";
        case TruncatedReason::kUnspecified:
            return "unspecified";
        default:
            return "invalid";
    }
}

warc::truncated_reason::TruncatedReason warc::truncated_reason::fromString(const std::string_view s) {
    if (s == "length") {
        return TruncatedReason::kLength;
    } else if (s == "time") {
        return TruncatedReason::kTime;
    } else if (s == "disconnect") {
        return TruncatedReason::kDisconnect;
    } else if (s == "unspecified") {
        return TruncatedReason::kUnspecified;
    }
    return TruncatedReason::kInvalid;
}

std::ostream& warc::truncated_reason::operator<<(std::ostream& os, TruncatedReason err) {
    return os << toString(err);
}

std::string_view warc::protocol::toString(Protocol protocol) {
    switch (protocol) {
        case Protocol::kDNS:
            return "dns";
        case Protocol::kFTP:
            return "ftp";
        case Protocol::kGemini:
            return "gemini";
        case Protocol::kGopher:
            return "gopher";
        case Protocol::kHTTP_0_9:
            return "http/0.9";
        case Protocol::kHTTP_1_0:
            return "http/1.0";
        case Protocol::kHTTP_1_1:
            return "http/1.1";
        case Protocol::kH2:
            return "h2";
        case Protocol::kH2c:
            return "h2c";
        case Protocol::kH3:
            return "h3";
        case Protocol::kQUIC_1:
            return "quic/1";
        case Protocol::kQUIC_2:
            return "quic/2";
        case Protocol::kSPDY_1:
            return "spdy/1";
        case Protocol::kSPDY_2:
            return "spdy/2";
        case Protocol::kSPDY_3:
            return "spdy/3";
        case Protocol::kSSL_2:
            return "ssl/2";
        case Protocol::kSSL_3:
            return "ssl/3";
        case Protocol::kTLS_1_0:
            return "tls/1.0";
        case Protocol::kTLS_1_1:
            return "tls/1.1";
        case Protocol::kTLS_1_2:
            return "tls/1.2";
        case Protocol::kTLS_1_3:
            return "tls/1.3";
        default:
            return "invalid";
    }
}

warc::protocol::Protocol warc::protocol::fromString(const std::string_view s) {
    if (s == "dns") {
        return Protocol::kDNS;
    } else if (s == "ftp") {
        return Protocol::kFTP;
    } else if (s == "gemini") {
        return Protocol::kGemini;
    } else if (s == "gopher") {
        return Protocol::kGopher;
    } else if (s == "http/0.9") {
        return Protocol::kHTTP_0_9;
    } else if (s == "http/1.0") {
        return Protocol::kHTTP_1_0;
    } else if (s == "http/1.1") {
        return Protocol::kHTTP_1_1;
    } else if (s == "h2") {
        return Protocol::kH2;
    } else if (s == "h2c") {
        return Protocol::kH2c;
    } else if (s == "h3") {
        return Protocol::kH3;
    } else if (s == "quic/1") {
        return Protocol::kQUIC_1;
    } else if (s == "quic/2") {
        return Protocol::kQUIC_2;
    } else if (s == "spdy/1") {
        return Protocol::kSPDY_1;
    } else if (s == "spdy/2") {
        return Protocol::kSPDY_2;
    } else if (s == "spdy/3") {
        return Protocol::kSPDY_3;
    } else if (s == "ssl/2") {
        return Protocol::kSSL_2;
    } else if (s == "ssl/3") {
        return Protocol::kSSL_3;
    } else if (s == "tls/1.0") {
        return Protocol::kTLS_1_0;
    } else if (s == "tls/1.1") {
        return Protocol::kTLS_1_1;
    } else if (s == "tls/1.2") {
        return Protocol::kTLS_1_2;
    } else if (s == "tls/1.3") {
        return Protocol::kTLS_1_3;
    }
    return Protocol::kInvalid;
}

std::ostream& warc::protocol::operator<<(std::ostream& os, Protocol protocol) {
    return os << toString(protocol);
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
        return Field::kWarcRecordID;
    } else if (caseInsensitiveEqual(s, "Content-Length")) {
        return Field::kContentLength;
    } else if (caseInsensitiveEqual(s, "WARC-Date")) {
        return Field::kWarcDate;
    } else if (caseInsensitiveEqual(s, "WARC-Type")) {
        return Field::kWarcType;
    } else if (caseInsensitiveEqual(s, "Content-Type")) {
        return Field::kContentType;
    } else if (caseInsensitiveEqual(s, "WARC-Concurrent-To")) {
        return Field::kWarcConcurrentTo;
    } else if (caseInsensitiveEqual(s, "WARC-Block-Digest")) {
        return Field::kWarcBlockDigest;
    } else if (caseInsensitiveEqual(s, "WARC-Payload-Digest")) {
        return Field::kWarcPayloadDigest;
    } else if (caseInsensitiveEqual(s, "WARC-IP-Address")) {
        return Field::kWarcIPAddress;
    } else if (caseInsensitiveEqual(s, "WARC-Refers-To")) {
        return Field::kWarcRefersTo;
    } else if (caseInsensitiveEqual(s, "WARC-Refers-To-Target-URI")) {
        return Field::kWarcRefersToTargetURI;
    } else if (caseInsensitiveEqual(s, "WARC-Refers-To-Date")) {
        return Field::kWarcRefersToDate;
    } else if (caseInsensitiveEqual(s, "WARC-Target-URI")) {
        return Field::kWarcTargetURI;
    } else if (caseInsensitiveEqual(s, "WARC-Truncated")) {
        return Field::kWarcTruncated;
    } else if (caseInsensitiveEqual(s, "WARC-Warcinfo-ID")) {
        return Field::kWarcWarcinfoID;
    } else if (caseInsensitiveEqual(s, "WARC-Filename")) {
        return Field::kWarcFilename;
    } else if (caseInsensitiveEqual(s, "WARC-Profile")) {
        return Field::kWarcProfile;
    } else if (caseInsensitiveEqual(s, "WARC-Identified-Payload-Type")) {
        return Field::kWarcIdentifiedPayloadType;
    } else if (caseInsensitiveEqual(s, "WARC-Segment-Number")) {
        return Field::kWarcSegmentNumber;
    } else if (caseInsensitiveEqual(s, "WARC-Segment-Origin-ID")) {
        return Field::kWarcSegmentOriginID;
    } else if (caseInsensitiveEqual(s, "WARC-Segment-Total-Length")) {
        return Field::kWarcSegmentTotalLength;
    } else if (caseInsensitiveEqual(s, "WARC-Protocol")) {
        return Field::kWarcProtocol;
    } else {
        return Field::kInvalid;
    }
}

std::ostream& warc::field::operator<<(std::ostream& os, Field field) {
    return os << toString(field);
}
