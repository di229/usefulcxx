#ifndef _USEFULCXX_CRYPTO_UTIL_H
#define _USEFULCXX_CRYPTO_UTIL_H

#include <vector>
#include <optional>
#include <string>

using OptString = std::optional<std::string>;

// This is the main type used for input and output data in usefulcxx's crypto
// APIs
using OptBytes = std::optional<std::vector<char>>;

// Returns a string containing the entire file contents, wrapped in
// std::optional, which is empty if the file read failed in any way
OptString ReadFile(std::string_view& path);

// Returns the length of the string excluding any trailing whitespace
int TrimTrailing(std::string& s);

#endif // _USEFULCXX_CRYPTO_UTIL_H
