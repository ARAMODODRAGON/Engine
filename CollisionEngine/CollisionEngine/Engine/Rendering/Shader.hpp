#ifndef RENDERING_SHADER_HPP
#define RENDERING_SHADER_HPP
#include "../Common.hpp"
#include <glew.h>

namespace Rendering {

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
}

#endif // !RENDERING_SHADER_HPP