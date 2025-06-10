#include <filesystem>
#include <fstream>
#include <iostream>

#include "warc.h"

int main(void) {
    // constexpr auto kFilename = "./data/test.warc";
    constexpr auto kFilename = "./data/CC-MAIN-20250512011722-20250512041722-00000.warc";
    const auto size = std::filesystem::file_size(kFilename);
    std::string content(size, '\0');
    std::ifstream in(kFilename);
    in.read(&content[0], size);

    // Start the timer
    const auto start = std::chrono::high_resolution_clock::now();

    std::string_view data(content);
    while (1) {
        warc::Record record;
        const auto [error, consumed] = record.parse(data, false);
        if (error != warc::error::Error::kSuccess) {
            std::cerr << "Got parse error: " << error << ", at: '" << data.substr(consumed, 30) << "'" << std::endl;
            // return EXIT_FAILURE;
            break;
        }
        // std::cout << "Type: " << record.warcType().first << std::endl;
        // std::cout << "Body:\n"
        //           << record.rawBody() << std::endl;
        // std::cout << "Consumed: " << consumed << std::endl;

        data.remove_prefix(consumed);
    }

    // Stop the timer
    const auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms\n";
}