#ifndef ENUM_H
#define ENUM_H

namespace warc {

namespace error {
enum class Error {
    kInvalid,
    kSuccess,
    kOther,
    kInvalidPrefix,
    kInvalidHeader,
    kInvalidField,
    kInvalidInteger,
    kInvalidResponseType,
    kInvalidTruncatedReason
};

std::string_view toString(Error error);
Error fromString(const std::string_view s);
std::ostream& operator<<(std::ostream& os, Error type);
}  // namespace error

namespace record_type {
enum class RecordType {
    kInvalid,
    kWarcinfo,
    kResponse,
    kResource,
    kRequest,
    kMetadata,
    kRevisit,
    kConversion,
    kContinuation
};

std::string_view toString(RecordType type);
RecordType fromString(const std::string_view s);
std::ostream& operator<<(std::ostream& os, RecordType type);
}  // namespace record_type

namespace truncated_reason {
enum class TruncatedReason {
    kInvalid,
    kLength,
    kTime,
    kDisconnect,
    kUnspecified
};

std::string_view toString(TruncatedReason reason);
TruncatedReason fromString(const std::string_view s);
std::ostream& operator<<(std::ostream& os, TruncatedReason type);
}  // namespace truncated_reason

namespace field {
enum class Field {
    kInvalid,
    kWarcRecordID,
    kContentLength,
    kWarcDate,
    kWarcType,
    kContentType,
    kWarcConcurrentTo,
    kWarcBlockDigest,
    kWarcPayloadDigest,
    kWarcIPAddress,
    kWarcRefersTo,
    kWarcRefersToTargetURI,
    kWarcRefersToDate,
    kWarcTargetURI,
    kWarcTruncated,
    kWarcWarcinfoID,
    kWarcFilename,
    kWarcProfile,
    kWarcIdentifiedPayloadType,
    kWarcSegmentNumber,
    kWarcSegmentOriginID,
    kWarcSegmentTotalLength
};

std::string_view toString(Field field);
Field fromString(const std::string_view s);
std::ostream& operator<<(std::ostream& os, Field field);
}  // namespace field

}  // namespace warc

#endif /* ENUM_H */