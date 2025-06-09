#include <filesystem>
#include <fstream>
#include <iostream>

#include "warc.h"

int main(void) {
    constexpr auto kFilename = "./data/test.warc";
    const auto size = std::filesystem::file_size(kFilename);
    std::string content(size, '\0');
    std::ifstream in(kFilename);
    in.read(&content[0], size);

    warc::Record record;
    const auto [error, next_index] = record.parse(content);
    if (error != warc::error::Error::kSuccess) {
        std::cerr << "Got parse error: " << error << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Next index: " << next_index << std::endl;
}