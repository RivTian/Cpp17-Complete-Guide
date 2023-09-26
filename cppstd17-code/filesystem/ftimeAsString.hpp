#include <string>
#include <chrono>
#include <filesystem>

std::string asString(const std::filesystem::file_time_type & tp) {
    using system_clock = std::chrono::system_clock;
    auto t = system_clock::to_time_t(tp + (system_clock::now()
                                           - decltype(tp)::clock::now()));
    // convert to calendar time (including skipping trailing newline):
    std::string ts = std::ctime(&t);
    ts.resize(ts.size() - 1);
    return ts;
}

