#include <fcntl.h>     // open
#include <sys/mman.h>  // mmap, munmap
#include <sys/stat.h>  // fstat
#include <unistd.h>    // close

#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string_view>

#include "warc.h"

std::pair<void *, size_t> mmap_file_to_string_view(const char *filename) {
    // Open file
    const auto fd = open(filename, O_RDONLY);
    if (fd == -1) {
        throw std::runtime_error("Failed to open file");
    }

    // Get file size
    struct stat sb {};
    if (fstat(fd, &sb) == -1) {
        close(fd);
        throw std::runtime_error("Failed to get file size");
    }
    const size_t length = sb.st_size;

    // Memory-map the file
    void *map = mmap(nullptr, length, PROT_READ, MAP_PRIVATE, fd, 0);
    // Can close the fd after mmap
    close(fd);
    if (map == MAP_FAILED) {
        throw std::runtime_error("mmap failed");
    }
    return {map, length};
}

int main(void) {
    // constexpr auto kFilename = "./data/test.warc";
    constexpr auto kFilename = "./data/CC-MAIN-20250512011722-20250512041722-00000.warc";
    // const auto size = std::filesystem::file_size(kFilename);
    // std::string content(size, '\0');
    // std::ifstream in(kFilename);
    // in.read(&content[0], size);

    auto [map, length] = mmap_file_to_string_view(kFilename);

    // Start the timer
    const auto start = std::chrono::high_resolution_clock::now();

    // std::string_view data(content);
    int count = 0;
    auto data = std::string_view(static_cast<const char *>(map), length);
    while (1) {
        warc::Record record;
        const auto [error, consumed] = record.parse(data, false);
        if (error != warc::error::Error::kSuccess) {
            std::cerr << "Got parse error: " << error << ", at: '" << data.substr(consumed, 30) << "'" << std::endl;
            break;
            // return EXIT_FAILURE;
        }
        // std::cout << "Type: " << record.warcType().first << std::endl;
        // std::cout << "Body:\n"
        // << record.rawBody().first << std::endl;
        // std::cout << "Consumed: " << consumed << std::endl;

        data.remove_prefix(consumed);
        count++;
    }
    munmap(map, length);

    // Stop the timer
    const auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Parsed " << count << " records in " << elapsed.count() << " ms\n";
}