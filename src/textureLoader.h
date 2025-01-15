#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H


#if IBM
#include <windows.h>
#endif
#if LIN
#include <GL/gl.h>
#endif
#if __GNUC__ && APL
#include <OpenGL/gl.h>
#endif
#if __GNUC__ && IBM
#include <GL/gl.h>
#endif

#include <map>

// GLuint loadTexture(const char *filePath);
GLuint loadSingleTexture(const char* filename);
// void loadDigitTextures();
// void load_gtx_intro();
// void load_gtx_bezel();
// extern std::map<char, GLuint> digitTextures;
// extern GLuint intro_texture;
// extern GLuint bezel_texture;


#endif // TEXTURE_LOADER_H
