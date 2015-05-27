#include <GLES2/gl2.h>

const char * fShaderPath;
const char * vShaderPath;

GLuint compile_shader(const GLenum type, const GLchar* source, const GLint length);
GLuint link_program(const GLuint vertex_shader, const GLuint fragment_shader);
GLuint build_program(const GLchar * vShaderSrc, const GLint veShaderLen, const GLchar * fShaderSrc, const GLint fShaderLen);
