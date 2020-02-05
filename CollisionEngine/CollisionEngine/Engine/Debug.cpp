#include "Debug.h"
#include <iostream>

void Debug::Print(std::string text) { 
	std::cout << text << std::endl;
}

void Debug::PrintError(std::string text) { 
	std::cout << "[ERROR]: " << text << std::endl;
}
