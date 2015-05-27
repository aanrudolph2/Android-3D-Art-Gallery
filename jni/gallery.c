#include "gallery.h"
#include <GLES2/gl2.h>
#include <stdio.h>

extern const char * fShaderPath;
extern const char * vShaderPath;

JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_createGLSurface(JNIEnv * env, jclass cls)
{
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
