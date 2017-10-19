//
//  Bounds.h
//  BouncingSpheres
//
//  Created by Tyler on 10/16/17.
//
//

#pragma once
#include "ofMain.h"

struct Bounds	// a struct is like a simple class
{
	
	// our bounds will be a 3D box, with these limits:
	
	float left		= 0;	// min x
	float right		= 0;	// max x
	float top		= 0;	// y
	float bottom		= 0;
	float front		= 0;	// z
	float back		= 0;
	
	// a few utility functions:
	
	ofVec3f getCenter()		// get the center point
	{
		ofVec3f c;
		c.x = (left + right) * .5;
		c.y = (top + bottom) * .5;
		c.z = (front + back) * .5;
		return c;
	}
	
	// get the dimensions
	
	float getWidth()	{ return right - left; }
	float getHeight()	{ return bottom - top; }
	float getDepth()	{ return back - front; }
	
};