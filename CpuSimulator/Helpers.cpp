#include "Helpers.h"

bool is_number(const std::string &str)
{
    std::string::const_iterator it = str.begin();
    while (std::isdigit(*it) && it != str.end()) {
        ++it;
    }
    return (it == str.end() && str.empty());
}

void to_lower(std::string &str)
{
    for (size_t i{}; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; 
        }
    }
}

size_t length(const std::string::const_iterator str, const char *ch)
{
    size_t len = 0;
    while (!str_char(ch, str[len]) && str[len]) {
        ++len;
    }
    return len;
}

bool str_char(const char *str, char ch)
{
    while (*str) {
        if (*str == ch) {
            return true;
        }
        str++;
    }
    if (*str == ch) {
        return true;
    }
    return false;
}

std::vector<std::string> splitter(const std::string &str, const char *ch)
{
    std::vector<std::string> tabs;
    size_t index = 0;
    while (str[index]) {
        while (str[index] && str_char(ch, str[index])) {
            ++index;
        }
        tabs.push_back(str.substr(index, length(str.begin() + index, ch)));
        index = index + length(str.begin() + index, ch);
    }
    return tabs;
}

void open_file(std::ifstream &input_file, int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Enter asm file for executing: " << std::endl;
        exit(EXIT_FAILURE);
    }
    input_file.open(argv[1]);
    
    if (!input_file.is_open()) {
        std::cout << "File cannot be openned: " << argv[1] << std::endl;
        exit(EXIT_FAILURE);
    }
}
