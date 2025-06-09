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

warc::error::Error fromString(const std::string_view s) {
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

std::string_view warc::field::toString(warc::field::Field field) {
    switch (field) {
        case Field::kWarcRecordID: return "WARC-Record-ID";
        case Field::kContentLength: return "Content-Length";
        case Field::kWarcDate: return "WARC-Date";
        case Field::kWarcType: return "WARC-Type";
        case Field::kContentType: return "Content-Type";
        case Field::kWarcConcurrentTo: return "WARC-Concurrent-To";
        case Field::kWarcBlockDigest: return "WARC-Block-Digest";
        case Field::kWarcPayloadDigest: return "WARC-Payload-Digest";
        case Field::kWarcIPAddress: return "WARC-IP-Address";
        case Field::kWarcRefersTo: return "WARC-Refers-To";
        case Field::kWarcRefersToTargetURI: return "WARC-Refers-To-Target-URI";
        case Field::kWarcRefersToDate: return "WARC-Refers-To-Date";
        case Field::kWarcTargetURI: return "WARC-Target-URI";
        case Field::kWarcTruncated: return "WARC-Truncated";
        case Field::kWarcWarcinfoID: return "WARC-Warcinfo-ID";
        case Field::kWarcFilename: return "WARC-Filename";
        case Field::kWarcProfile: return "WARC-Profile";
        case Field::kWarcIdentifiedPayloadType: return "WARC-Identified-Payload-Type";
        case Field::kWarcSegmentNumber: return "WARC-Segment-Number";
        case Field::kWarcSegmentOriginID: return "WARC-Segment-Origin-ID";
        case Field::kWarcSegmentTotalLength: return "WARC-Segment-Total-Length";
        default: return "Invalid";
    }
}

warc::field::Field fromString(std::string_view s) {
    if (s == "WARC-Record-ID") {
        return warc::Field::kWarcRecordID;
    } else if (s == "Content-Length") {
        return warc::Field::kContentLength;
    } else if (s == "WARC-Date") {
        return warc::Field::kWarcDate;
    } else if (s == "WARC-Type") {
        return warc::Field::kWarcType;
    } else if (s == "Content-Type") {
        return warc::Field::kContentType;
    } else if (s == "WARC-Concurrent-To") {
        return warc::Field::kWarcConcurrentTo;
    } else if (s == "WARC-Block-Digest") {
        return warc::Field::kWarcBlockDigest;
    } else if (s == "WARC-Payload-Digest") {
        return warc::Field::kWarcPayloadDigest;
    } else if (s == "WARC-IP-Address") {
        return warc::Field::kWarcIPAddress;
    } else if (s == "WARC-Refers-To") {
        return warc::Field::kWarcRefersTo;
    } else if (s == "WARC-Refers-To-Target-URI") {
        return warc::Field::kWarcRefersToTargetURI;
    } else if (s == "WARC-Refers-To-Date") {
        return warc::Field::kWarcRefersToDate;
    } else if (s == "WARC-Target-URI") {
        return warc::Field::kWarcTargetURI;
    } else if (s == "WARC-Truncated") {
        return warc::Field::kWarcTruncated;
    } else if (s == "WARC-Warcinfo-ID") {
        return warc::Field::kWarcWarcinfoID;
    } else if (s == "WARC-Filename") {
        return warc::Field::kWarcFilename;
    } else if (s == "WARC-Profile") {
        return warc::Field::kWarcProfile;
    } else if (s == "WARC-Identified-Payload-Type") {
        return warc::Field::kWarcIdentifiedPayloadType;
    } else if (s == "WARC-Segment-Number") {
        return warc::Field::kWarcSegmentNumber;
    } else if (s == "WARC-Segment-Origin-ID") {
        return warc::Field::kWarcSegmentOriginID;
    } else if (s == "WARC-Segment-Total-Length") {
        return warc::Field::kWarcSegmentTotalLength;
    } else {
        return warc::Field::kInvalid;
    }
}

std::ostream& warc::field::operator<<(std::ostream& os, warc::field::Field field) {
    return os << warc::field::toString(field);
}
