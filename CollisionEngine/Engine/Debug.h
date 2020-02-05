#include "Common.h"
#ifndef DEBUG_H
#define DEBUG_H
#include <string>

class Debug {

public:

	static void Print(std::string text);
	static void PrintError(std::string text);

};

#endif // !DEBUG_H