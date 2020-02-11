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

#include <memory>
// used to quickly create a singleton class
#define SINGLETON_DECLERATION(TYPE) \
	static std::unique_ptr<TYPE> singleton; \
	friend std::default_delete<TYPE>; \
	~TYPE() { } \
	TYPE(const TYPE&) = delete; \
	TYPE& operator=(const TYPE&) = delete; \
	TYPE(TYPE&&) = delete; \
	TYPE& operator=(TYPE&&) = delete; \
	public: \
	static TYPE* GetSingleton() { \
		if (singleton.get() == nullptr) \
			singleton.reset(new TYPE); \
		return singleton.get(); \
	} \
	private:\
	TYPE()

// the definition for the singleton pointer
#define SINGLETON_DEFINITION(TYPE)\
	std::unique_ptr<TYPE> TYPE::singleton = nullptr;\

#endif // !COMMON_HPP