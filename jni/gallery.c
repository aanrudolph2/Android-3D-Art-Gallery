#include "gallery.h"

GLint vertBuffer;
GLint positionHandle;
GLuint shaderProg;

float verts[] = 	{1, 0, 0,
					 0, 1, 0,
					 -1, 0, 0};

JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_createGLSurface(JNIEnv * env, jclass cls)
{

	const char * frag_shader_src =
		"	precision mediump float;\
			void main()\
			{\
				gl_FragColor = vec4(1, 1, 1, 1);\
			}";
	const char * vert_shader_src =
		"	attribute vec4 a_Position;\
			\
			void main()\
			{\
			    gl_Position = a_Position;\
			}";

	shaderProg = build_program(vert_shader_src, strlen(vert_shader_src), frag_shader_src, strlen(frag_shader_src));

	glGenBuffers(1, &vertBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glUseProgram(shaderProg);

	positionHandle = glGetAttribLocation(shaderProg, "a_Position");

	glClearColor(0, 0, 0, 0);

}
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_changeGLSurface(JNIEnv * env, jclass cls, jint w, jint h)
{
	glViewport(0, 0, w, h);
}
JNIEXPORT void JNICALL Java_com_rudy_artgallery_GallerySurfaceView_drawFrame(JNIEnv * env, jclass cls)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);

	glVertexAttribPointer(positionHandle, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(positionHandle);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(positionHandle);

}
