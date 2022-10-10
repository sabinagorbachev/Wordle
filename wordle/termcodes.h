#ifndef TERMCODES_H 
#define TERMCODES_H 
#include <string>

// Use these for the colour version
const std::string YELLOW =  "\033[33m";
const std::string GREEN = "\033[32m";

// Use these for the monochrome version
const std::string UNDERLINE = "\033[4m";
const std::string REVERSE = "\033[7m";

// Use this for both versions
const std::string RESET =  "\033[0m";
#endif
