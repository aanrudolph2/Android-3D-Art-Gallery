#include "gallery.h"

extern const char * fShaderPath;
extern const char * vShaderPath;

JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_createGLSurface(JNIEnv * env, jclass cls)
{
	long int frag_shader_len = -1;
	long int vert_shader_len = -1;

	char * frag_shader_src;
	char * vert_shader_src;

	FILE * frag_shader = fopen(fShaderPath, "rb");
	FILE * vert_shader = fopen(vShaderPath, "rb");

	// Get length of fragment shader
	if(fseek(frag_shader, 0, SEEK_END))
	{
		frag_shader_len = ftell(frag_shader);
		frag_shader_src = malloc(frag_shader_len * sizeof(char));

		frag_shader_len = fread(frag_shader_src, 1, frag_shader_len, frag_shader);
	}

	fclose(frag_shader);

	// Get length of vertex shader
	if(fseek(vert_shader, 0, SEEK_END))
	{
		vert_shader_len = ftell(vert_shader);
		vert_shader_src = malloc(vert_shader_len * sizeof(char));

		vert_shader_len = fread(vert_shader_src, 1, vert_shader_len, vert_shader);
	}

	fclose(vert_shader);

	if(frag_shader_len > -1 && vert_shader_len > -1)
	{
		build_program(vert_shader_src, vert_shader_len, frag_shader_src, frag_shader_len);

		free(vert_shader_src);
		free(frag_shader_src);
	}

	glClearColor(1, 0, 0, 0);
}
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_changeGLSurface(JNIEnv * env, jclass cls, jint w, jint h)
{
	glViewport(0, 0, w, h);
}
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_drawFrame(JNIEnv * env, jclass cls)
{
	glClear(GL_COLOR_BUFFER_BIT);
}
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_loadShaderSrc (JNIEnv * env, jclass cls, jstring fShader, jstring vShader)
{
	fShaderPath = (*env)->GetStringUTFChars(env, fShader, 0);
	vShaderPath = (*env)->GetStringUTFChars(env, vShader, 0);
}
