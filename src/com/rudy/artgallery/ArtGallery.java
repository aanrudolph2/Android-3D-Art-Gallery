package com.rudy.artgallery;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

import android.app.Activity;
import android.content.SharedPreferences;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.util.Log;
import android.widget.Toast;

/**
 * An example full-screen activity that shows and hides the system UI (i.e.
 * status bar and navigation/system bar) with user interaction.
 * 
 * @see SystemUiHider
 */
public class ArtGallery extends Activity
{
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);

		SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
		
		boolean firstRun = prefs.getBoolean("FIRSTRUN", true);
		
		if(firstRun)
		{
			SharedPreferences.Editor editor = prefs.edit();
			editor.putBoolean("FIRSTRUN", false);
			editor.commit();
			
			AssetManager mgr = getAssets();
			try
			{
				InputStream iStream = mgr.open("fShader");
				String shaderDir = getDir("com.rudy.artgallery", MODE_PRIVATE).getPath() + File.separator;
				Scanner s = new Scanner(iStream);
				FileOutputStream oStream = new FileOutputStream(shaderDir + "fshader");
				
				Log.d("com.rudy.artgallery", "Writing Fragment Shaders");
				
				while(s.hasNextLine())
				{
					String tmp = s.nextLine();
					
					Log.d("com.rudy.artgallery", "F: " + tmp);
					oStream.write(tmp.getBytes());
				}
				
				s.close();
				
				oStream.close();
				
				iStream = mgr.open("vShader");
				s = new Scanner(iStream);
				oStream = new FileOutputStream(shaderDir + "vshader");
				
				Log.d("com.rudy.artgallery", "Writing Vertex Shaders");
				
				while(s.hasNextLine())
				{
					String tmp = s.nextLine();
					
					Log.d("com.rudy.artgallery", "V: " + tmp);
					oStream.write(tmp.getBytes());
				}
				
				s.close();
				
				oStream.close();
			}
			catch (IOException e)
			{
				System.exit(1);
			}
			
		}
		
		setContentView(R.layout.art_gallery);
	}
	
	private boolean isFirstlaunch()
	{
		return false;
	}
}
