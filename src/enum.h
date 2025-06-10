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
    kInvalidTruncatedReason,
    kMissingMandatoryField,
    kInvalidContentLength,
    kInvalidProtocol
};

std::string_view toString(Error error);
Error fromString(const std::string_view s);
std::ostream& operator<<(std::ostream& os, Error type);
}  // namespace error

namespace record_type {
// record-type = "warcinfo" | "response" | "resource" | "request" |
// "metadata" | "revisit" | "conversion" | "continuation"
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
// reason-token   = "length"         ; exceeds configured max
//                                   ; length
//                | "time"           ; exceeds configured max time
//                | "disconnect"     ; network disconnect
//                | "unspecified"    ; other/unknown reason
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

namespace protocol {

enum class Protocol {
    kInvalid,
    kDns,
    kFtp,
    kGemini,
    kGopher,
    kHttp_0_9,
    kHttp_1_0,
    kHttp_1_1,
    kH2,
    kH2c,
    kH3,
    kQuic_1,
    kQuic_2,
    kSpdy_1,
    kSpdy_2,
    kSpdy_3,
    kSsl_2,
    kSsl_3,
    kTls_1_0,
    kTls_1_1,
    kTls_1_2,
    kTls_1_3
};

std::string_view toString(Protocol protocol);
Protocol fromString(const std::string_view s);
std::ostream& operator<<(std::ostream& os, Protocol protocol);
}  // namespace protocol

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
    kWarcSegmentTotalLength,
    kWarcProtocol
};

std::string_view toString(Field field);
Field fromString(const std::string_view s);
std::ostream& operator<<(std::ostream& os, Field field);
}  // namespace field

}  // namespace warc

#endif /* ENUM_H */