package com.rudy.artgallery;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

public class GallerySurfaceView extends GLSurfaceView
{
	static
	{
		System.loadLibrary("gallery");
	}
	
	private static native void createGLSurface();
	private static native void changeGLSurface(int width, int height);
	private static native void drawFrame();
	private static native void setShaderDir(String vShader, String fShader);
	
	public GallerySurfaceView(Context context, AttributeSet attrs)
	{
		super(context, attrs);
		
		setEGLContextClientVersion(2);
		setRenderer(new GalleryRenderer());
	}
	
	private class GalleryRenderer implements GLSurfaceView.Renderer
	{

		@Override
		public void onDrawFrame(GL10 gl)
		{
			drawFrame();
		}

		@Override
		public void onSurfaceChanged(GL10 gl, int width, int height)
		{
			changeGLSurface(width, height);
		}

		@Override
		public void onSurfaceCreated(GL10 gl, EGLConfig config)
		{
			createGLSurface();
		}
		
	}
}
