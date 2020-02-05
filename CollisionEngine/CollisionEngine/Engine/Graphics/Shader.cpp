#include "Shader.h"
#include "../Debug.h"
#include <fstream>
using std::ifstream;
using std::getline;

Shader::Shader() : programID(0) { }

Shader::~Shader() { UnloadShader(); }

void Shader::LoadShader(const string& vertpath, const string& fragpath) {
	// delete the old program if there is one
	if (programID) UnloadShader();

	// load the vertex file
	string vertsourcestring = LoadSource(vertpath);
	const char* vertsource = vertsourcestring.c_str();
	
	//Debug::Print("Loaded vertex: \n");
	//Debug::Print(vertsource);
	
	// create vertex shader
	GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
	// load and compile the code
	glShaderSource(vertID, 1, &vertsource, 0);
	glCompileShader(vertID);

	/// check errors
	GLint success;
	glGetShaderiv(vertID, GL_COMPILE_STATUS, &success);
	if (!success) {
		// get error and print
		GLchar infoLog[512];
		glGetShaderInfoLog(vertID, 512, 0, infoLog);
		Debug::PrintError("Failed to compile shader: " + string(infoLog) + "\n\n");

		// delete the shader and return
		glDeleteShader(vertID);
		return;
	}

	// load the fragment file
	string fragsourcestring = LoadSource(fragpath);
	const char* fragsource = fragsourcestring.c_str();

	//Debug::Print("Loaded fragment: \n");
	//Debug::Print(fragsource);

	// create vertex shader
	GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);
	// load and compile the code
	glShaderSource(fragID, 1, &fragsource, 0);
	glCompileShader(fragID);

	/// check errors
	glGetShaderiv(vertID, GL_COMPILE_STATUS, &success);
	if (!success) {
		// get error and print
		GLchar infoLog[512];
		glGetShaderInfoLog(vertID, 512, 0, infoLog);
		Debug::PrintError("Failed to compile shader: " + string(infoLog) + "\n\n");

		// delete the shader and return
		glDeleteShader(vertID);
		return;
	}


	// create program
	programID = glCreateProgram();

	// attach and link shaders
	glAttachShader(programID, vertID);
	glAttachShader(programID, fragID);
	glLinkProgram(programID);

	// check linking errors
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		// get error message and print
		GLchar infoLog[512];
		glGetProgramInfoLog(programID, 512, 0, infoLog);
		Debug::Print("Failed to link program: " + string(infoLog));
	}

	// delete shaders
	glDeleteShader(vertID);
	glDeleteShader(fragID);
}

void Shader::UnloadShader() {
	// if there is a program, delete it
	if (!programID) glDeleteProgram(programID);
}

void Shader::UseProgram() {
	// use the program if its not 0
	if (programID) glUseProgram(programID);
}

////////////// static functions

string Shader::LoadSource(const string& filepath) {
	// file stream
	ifstream stream;
	stream.open(filepath);

	if (!stream.is_open()) {
		// failed to open file
		Debug::PrintError("Failed to open file " + filepath);
		stream.close();
		return "";
	}

	// stores the code
	string source, line;

	// read every line from the shader
	// add \0 to the end to tell the compiler that this is the end of the file
	while (getline(stream, line))
		source.append(line).append("\n");
	source.append("\0");

	//Debug::Print(source);

	// finish and return
	stream.close();
	return source;
}
