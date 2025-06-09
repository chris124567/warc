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
        case warc::error::Error::kInvalidInteger:
            return "invalid_integer";
        case warc::error::Error::kInvalidResponseType:
            return "invalid_response_type";
        case warc::error::Error::kInvalidTruncatedReason:
            return "invalid_truncated_reason";
        default:
            return "invalid";
    }
}

warc::error::Error fromString(std::string_view s) {
    if (s == "success") {
        return warc::error::Error::kSuccess;
    } else if (s == "other") {
        return warc::error::Error::kOther;
    } else if (s == "invalid_prefix") {
        return warc::error::Error::kInvalidPrefix;
    } else if (s == "invalid_header") {
        return warc::error::Error::kInvalidHeader;
    } else if (s == "invalid_integer") {
        return warc::error::Error::kInvalidInteger;
    } else if (s == "invalid_response_type") {
        return warc::error::Error::kInvalidResponseType;
    } else if (s == "invalid_truncated_reason") {
        return warc::error::Error::kInvalidTruncatedReason;
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

warc::record_type::RecordType warc::record_type::fromString(std::string_view s) {
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
