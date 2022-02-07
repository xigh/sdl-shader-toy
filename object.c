#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#ifdef __APPLE__
#include <OpenGL/GL.h>
#include <OpenGL/GLext.h>
#else
#include <GL/gl.h>
#include <GL/glext.h>
#endif

GLfloat vertices[] = {
	-0.5f, -0.5f, +5.0f,
	+0.5f, -0.5f, +5.0f,
	+0.5f, +0.5f, +5.0f,
	-0.5f, +0.5f, +5.0f,
	-0.5f, -0.5f, -5.0f,
	+0.5f, -0.5f, -5.0f,
	+0.5f, +0.5f, -5.0f,
	-0.5f, +0.5f, -5.0f,
};
GLuint vCount = 8 * 3;

GLint indices[] = {
    0, 2, 1,
    3, 2, 0,
};
GLuint iCount = 2 * 3;
