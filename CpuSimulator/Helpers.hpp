#ifndef HELPERS
#define HELPERS

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

bool is_number(const std::string& str);
void to_lower(std::string& str);
size_t length(const std::string::const_iterator str, const char* s);
bool str_char(const char* str, char ch);
std::vector<std::string> splitter(const std::string& str, const char* ch);
void open_file(std::ifstream& input_file, int argc, char** argv);
void label_checker(std::string& line);
void label_mapper(std::vector<std::string> &str, size_t line, std::multimap<std::string, size_t> &labels);

// #include "Helpers.cpp"
#endif