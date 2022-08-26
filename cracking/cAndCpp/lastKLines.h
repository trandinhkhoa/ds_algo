#include <string>

namespace cracking {

namespace cAndCpp {

std::vector<std::string> printLastKLines(const std::string& iFilePath, const int& K);
std::vector<std::string> printLastKLines_Stupid(const std::string& iFilePath, const int& K);
std::vector<std::string> printLastKLines_usingQueue(const std::string& iFilePath, const int& K);
std::vector<std::string> printLastKLines_usingDeque(const std::string& iFilePath, const int& K);

}

}