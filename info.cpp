#include <string>
#include <cstdlib>

// The Intrinio key is read from the INTRINIO_API_KEY environment variable; it is never committed.
static std::string envOrEmpty(const char* name) {
    const char* v = std::getenv(name);
    return v ? std::string(v) : std::string();
}

std::string APIKey = envOrEmpty("INTRINIO_API_KEY");
