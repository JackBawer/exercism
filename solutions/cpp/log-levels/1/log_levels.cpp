#include <string>

namespace log_line {
    std::string message(std::string line) {
        // return the message
        std::string delimeter = " ";
        std::string first_token = line.substr(0, line.find(delimeter));
        std::string second_token = line.substr(first_token.length() + delimeter.length(), line.length());
        return second_token;
    }

    std::string log_level(std::string line) {
        // return the log level
        int start = line.find("[");
        int stop = line.find("]");
        std::string res = line.substr(start + 1, stop - start - 1);
        return res;
    }

    std::string reformat(std::string line) {
        // return the reformatted message
        std::string msg = message(line);
        std::string lvl = log_level(line);
        return msg + " (" + lvl + ")";
    }
}  // namespace log_line
