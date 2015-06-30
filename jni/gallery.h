#include <jni.h>
#include <GLES2/gl2.h>
#include "util/shader.h"

/* Header for class com_rudy_artgallery_JNIWrapper */

#ifndef _Included_com_rudy_artgallery_JNIWrapper
#define _Included_com_rudy_artgallery_JNIWrapper

/*
 * Class:     com_rudy_artgallery_JNIWrapper
 * Method:    createGLSurface
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_createGLSurface
  (JNIEnv *, jclass);

/*
 * Class:     com_rudy_artgallery_JNIWrapper
 * Method:    changeGLSurface
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_changeGLSurface
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_rudy_artgallery_JNIWrapper
 * Method:    drawFrame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_drawFrame
  (JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_setShaderDir
  (JNIEnv *, jclass, jstring, jstring);

#endif
