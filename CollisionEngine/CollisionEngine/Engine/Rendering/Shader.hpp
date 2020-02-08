#ifndef SHADER_HPP
#define SHADER_HPP
#include "../Common.hpp"
#include <glew.h>
#include <map>

class Shader {
	// shader program
	GLuint programID;

public:

	Shader();
	~Shader();


	/// functions

	void LoadShader(const string& vertpath, const string& fragpath);
	void UnloadShader();

	void UseProgram();


	/// getters

	GLuint GetProgramID() { return programID; }

private:

	/// static functions
	static string LoadSource(const string& filepath);

};

#endif // !SHADER_HPP