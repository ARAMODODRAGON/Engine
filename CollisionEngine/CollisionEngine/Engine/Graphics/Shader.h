#ifndef SHADER_H
#define SHADER_H
#include "../Common.h"
#include <glew.h>
#include <map>

class Shader { 
	// shader program
	GLuint programID;

public:

	Shader();
	~Shader();

	// loading 
	void LoadShader(const string& vertpath, const string& fragpath);
	void UnloadShader();

	// using the program
	void UseProgram();

	// getter
	GLuint GetProgramID() { return programID; }

	// uniform setters

private:

	// static funcs
	static string LoadSource(const string& filepath);

};

#endif // !SHADER_H