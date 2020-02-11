#ifndef COMMON_HPP
#define COMMON_HPP

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char ubyte;

#include <string>
using std::string;

#include <iostream>

#define TEXT(value) std::to_string(value)
#define PRINT(message) std::cout << message << std::endl
#define PRINT_ERROR(message) std::cout << "[ERROR]: " << message << std::endl << " -{FILE}: (Line:" << __LINE__ << ") " << __FILE__ << std::endl

#endif // !COMMON_HPP