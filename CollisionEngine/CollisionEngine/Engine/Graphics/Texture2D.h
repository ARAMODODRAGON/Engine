#ifndef TEXTURE2D_H
#define TEXTURE2D_H
#include "../Common.h"
#include <string>
using std::string;
#include <glew.h>

class Texture2D { 
private:
	// texture ID
	GLuint texID;

	// image data
	ubyte bytesPerPixel;
	uint width, height;
	
public:

	Texture2D();
	~Texture2D();

	// load image
	void LoadImage(string filepath);
	void UnloadImage();

	// binding
	void BindImage();

	// getter
	GLuint GetTextureID() { return texID; }
};


#endif // !TEXTURE2D_H