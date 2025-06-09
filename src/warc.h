#ifndef WARC_H
#define WARC_H

#include <string>
#include <string_view>
#include <utility>

#include "enum.h"

namespace warc {

class Record {
   public:
    Record();
    // parse returns a parsing error (Error::Success if there was none) and the
    // amount of bytes consumed.  You can use the amount of bytes consumed to
    // adjust the string_view to get the next record if you are working with
    // multiple records.
    std::pair<warc::error::Error, size_t> parse(const std::string_view data);

    // warcRecordID returns the value of the WARC-Record-ID header.
    std::pair<std::string_view, bool> warcRecordID() const;

    // contentLength returns the value of the Content-Length header.
    std::pair<size_t, bool> contentLength() const;

    // warcDate returns the value of the WARC-Date header.
    std::pair<std::string_view, bool> warcDate() const;

    // warcType returns the value of the WARC-Type header.
    std::pair<record_type::RecordType, bool> warcType() const;

    // contentType returns the value of the Content-Type header.
    std::pair<std::string_view, bool> contentType() const;

    // warcConcurrentTo returns the value of the WARC-Concurrent-To header.
    std::pair<std::string_view, bool> warcConcurrentTo() const;

    // warcBlockDigest returns the value of the WARC-Block-Digest header.
    std::pair<std::string_view, bool> warcBlockDigest() const;

    // warcPayloadDigest returns the value of the WARC-Payload-Digest header.
    std::pair<std::string_view, bool> warcPayloadDigest() const;

    // warcIPAddress returns the value of the WARC-IP-Address header.
    std::pair<std::string_view, bool> warcIPAddress() const;

    // warcRefersTo returns the value of the WARC-Refers-To header.
    std::pair<std::string_view, bool> warcRefersTo() const;

    // warcRefersToTargetURI returns the value of the WARC-Refers-To-Target-URI header.
    std::pair<std::string_view, bool> warcRefersToTargetURI() const;

    // warcRefersToDate returns the value of the WARC-Refers-To-Date header.
    std::pair<std::string_view, bool> warcRefersToDate() const;

    // warcTargetURI returns the value of the WARC-Target-URI header.
    std::pair<std::string_view, bool> warcTargetURI() const;

    // warcTruncated returns the value of the WARC-Truncated header.
    std::pair<truncated_reason::TruncatedReason, bool> warcTruncated() const;

    // warcWarcinfoID returns the value of the WARC-Warcinfo-ID header.
    std::pair<std::string_view, bool> warcWarcinfoID() const;

    // warcFilename returns the value of the WARC-Filename header.
    std::pair<std::string_view, bool> warcFilename() const;

    // warcProfile returns the value of the WARC-Profile header.
    std::pair<std::string_view, bool> warcProfile() const;

    // warcIdentifiedPayloadType returns the value of the WARC-Identified-Payload-Type header.
    std::pair<std::string_view, bool> warcIdentifiedPayloadType() const;

    // warcSegmentNumber returns the value of the WARC-Segment-Number header.
    std::pair<size_t, bool> warcSegmentNumber() const;

    // warcSegmentOriginID returns the value of the WARC-Segment-Origin-ID header.
    std::pair<std::string_view, bool> warcSegmentOriginID() const;

    // warcSegmentTotalLength returns the value of the WARC-Segment-Total-Length header.
    std::pair<size_t, bool> warcSegmentTotalLength() const;

   private:
    std::pair<std::string_view, bool> warcRecordID_{};
    std::pair<size_t, bool> contentLength_{};
    std::pair<std::string_view, bool> warcDate_{};
    std::pair<record_type::RecordType, bool> warcType_{};
    std::pair<std::string_view, bool> contentType_{};
    std::pair<std::string_view, bool> warcConcurrentTo_{};
    std::pair<std::string_view, bool> warcBlockDigest_{};
    std::pair<std::string_view, bool> warcPayloadDigest_{};
    std::pair<std::string_view, bool> warcIPAddress_{};
    std::pair<std::string_view, bool> warcRefersTo_{};
    std::pair<std::string_view, bool> warcRefersToTargetURI_{};
    std::pair<std::string_view, bool> warcRefersToDate_{};
    std::pair<std::string_view, bool> warcTargetURI_{};
    std::pair<truncated_reason::TruncatedReason, bool> warcTruncated_{};
    std::pair<std::string_view, bool> warcWarcinfoID_{};
    std::pair<std::string_view, bool> warcFilename_{};
    std::pair<std::string_view, bool> warcProfile_{};
    std::pair<std::string_view, bool> warcIdentifiedPayloadType_{};
    std::pair<size_t, bool> warcSegmentNumber_{};
    std::pair<std::string_view, bool> warcSegmentOriginID_{};
    std::pair<size_t, bool> warcSegmentTotalLength_{};
};
}  // namespace warc

#endif /* WARC_H */