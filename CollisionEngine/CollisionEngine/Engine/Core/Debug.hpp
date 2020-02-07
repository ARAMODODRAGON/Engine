#ifndef DEBUG_HPP
#define DEBUG_HPP
#include "../Common.hpp"
#include <string>

class Debug {

public:

	static void Print(std::string text);
	static void PrintError(std::string text);

};

#endif // !DEBUG_HPP