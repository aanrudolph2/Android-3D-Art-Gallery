#include "shader.h"

GLuint compile_shader(const GLenum type, const GLchar* source, const GLint length)
{
	GLuint shader_obj = glCreateShader(type);

	glShaderSource(shader_obj, 1, source, length);
	glCompileShader(shader_obj);

	return shader_obj;
}

GLuint link_program(const GLuint vertex_shader, const GLuint fragment_shader)
{
	GLuint program_obj = glCreateProgram();

	glAttachShader(program_obj, vertex_shader);
	glAttachShader(program_obj, fragment_shader);

	glLinkProgram(program_obj);

	return program_obj;
}

GLuint build_program(const GLchar * vShaderSrc, const GLint vShaderLen, const GLchar * fShaderSrc, const GLint fShaderLen)
{
	GLuint vShader = compile_shader(GL_VERTEX_SHADER, vShaderSrc, vShaderLen);
	GLuint fShader = compile_shader(GL_FRAGMENT_SHADER, fShaderSrc, fShaderLen);

	return link_program(vShader, fShader);
}
