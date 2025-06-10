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
    // multiple records.  If strict is true, we will error on unknown fields
    // rather than just ignoring them.
    std::pair<warc::error::Error, size_t> parse(const std::string_view data, bool strict) noexcept;

    // warcRecordID returns the value of the WARC-Record-ID header.
    [[nodiscard]] constexpr auto warcRecordID() const noexcept {
        return warcRecordID_;
    }

    // contentLength returns the value of the Content-Length header.
    [[nodiscard]] constexpr auto contentLength() const noexcept {
        return contentLength_;
    }

    // warcDate returns the value of the WARC-Date header.
    [[nodiscard]] constexpr auto warcDate() const noexcept {
        return warcDate_;
    }

    // warcType returns the value of the WARC-Type header.
    [[nodiscard]] constexpr auto warcType() const noexcept {
        return warcType_;
    }

    // contentType returns the value of the Content-Type header.
    [[nodiscard]] constexpr auto contentType() const noexcept {
        return contentType_;
    }

    // warcConcurrentTo returns the value of the WARC-Concurrent-To header.
    [[nodiscard]] constexpr auto warcConcurrentTo() const noexcept {
        return warcConcurrentTo_;
    }

    // warcBlockDigest returns the value of the WARC-Block-Digest header.
    [[nodiscard]] constexpr auto warcBlockDigest() const noexcept {
        return warcBlockDigest_;
    }

    // warcPayloadDigest returns the value of the WARC-Payload-Digest header.
    [[nodiscard]] constexpr auto warcPayloadDigest() const noexcept {
        return warcPayloadDigest_;
    }

    // warcIPAddress returns the value of the WARC-IP-Address header.
    [[nodiscard]] constexpr auto warcIPAddress() const noexcept {
        return warcIPAddress_;
    }

    // warcRefersTo returns the value of the WARC-Refers-To header.
    [[nodiscard]] constexpr auto warcRefersTo() const noexcept {
        return warcRefersTo_;
    }

    // warcRefersToTargetURI returns the value of the WARC-Refers-To-Target-URI header.
    [[nodiscard]] constexpr auto warcRefersToTargetURI() const noexcept {
        return warcRefersToTargetURI_;
    }

    // warcRefersToDate returns the value of the WARC-Refers-To-Date header.
    [[nodiscard]] constexpr auto warcRefersToDate() const noexcept {
        return warcRefersToDate_;
    }

    // warcTargetURI returns the value of the WARC-Target-URI header.
    [[nodiscard]] constexpr auto warcTargetURI() const noexcept {
        return warcTargetURI_;
    }

    // warcTruncated returns the value of the WARC-Truncated header.
    [[nodiscard]] constexpr auto warcTruncated() const noexcept {
        return warcTruncated_;
    }

    // warcWarcinfoID returns the value of the WARC-Warcinfo-ID header.
    [[nodiscard]] constexpr auto warcWarcinfoID() const noexcept {
        return warcWarcinfoID_;
    }

    // warcFilename returns the value of the WARC-Filename header.
    [[nodiscard]] constexpr auto warcFilename() const noexcept {
        return warcFilename_;
    }

    // warcProfile returns the value of the WARC-Profile header.
    [[nodiscard]] constexpr auto warcProfile() const noexcept {
        return warcProfile_;
    }

    // warcIdentifiedPayloadType returns the value of the WARC-Identified-Payload-Type header.
    [[nodiscard]] constexpr auto warcIdentifiedPayloadType() const noexcept {
        return warcIdentifiedPayloadType_;
    }

    // warcSegmentNumber returns the value of the WARC-Segment-Number header.
    [[nodiscard]] constexpr auto warcSegmentNumber() const noexcept {
        return warcSegmentNumber_;
    }

    // warcSegmentOriginID returns the value of the WARC-Segment-Origin-ID header.
    [[nodiscard]] constexpr auto warcSegmentOriginID() const noexcept {
        return warcSegmentOriginID_;
    }

    // warcSegmentTotalLength returns the value of the WARC-Segment-Total-Length header.
    [[nodiscard]] constexpr auto warcSegmentTotalLength() const noexcept {
        return warcSegmentTotalLength_;
    }

    // warcProtocol returns the value of the WARC-Protocol header.
    [[nodiscard]] constexpr auto warcProtocol() const noexcept {
        return warcProtocol_;
    }

    // rawBody returns the value of the content body.
    [[nodiscard]] constexpr auto rawBody() const noexcept {
        return rawBody_;
    }

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
    std::pair<protocol::Protocol, bool> warcProtocol_{};

    std::string_view rawBody_;
};
}  // namespace warc

#endif /* WARC_H */