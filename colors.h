// colors.h
#include<iostream>
#ifndef COLORS_H
#define COLORS_H

// ANSI escape codes for text colors
const std::string black = "\033[30m";
const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string yellow = "\033[33m";
const std::string blue = "\033[34m";
const std::string magenta = "\033[35m";
const std::string cyan = "\033[36m";
const std::string white = "\033[37m";

// ANSI escape codes for text styles
const std::string bold = "\033[1m";
const std::string underline = "\033[4m";
const std::string reverse = "\033[7m";

// ANSI escape code for resetting text attributes
const std::string reset = "\033[0m";

#endif // COLORS_H
