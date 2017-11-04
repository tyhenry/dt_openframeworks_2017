//
//  SlitScan.hpp
//  3DSlitScan
//
//  Created by Tyler on 11/3/17.
//
//

#pragma once 
#include "ofMain.h"

class SlitScan
{
public:
	
	SlitScan();
	SlitScan(int w, int h);
	
	ofFbo fbo;		// offscreen drawing buffer

	
	void addLine( ofTexture source );
	
	void draw(float x, float y, float w, float h);
	
	
	// bind and unbind the fbo's texture
	// to map it to meshes
	void bind();
	void unbind();
	
	ofPixels getPixels();	// read the fbo texture to pixels
	
	
private:
	
	int width, height;
	int lineNum;		// which line to draw to

	
};