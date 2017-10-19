//
//  Sphere.hpp
//  BouncingSpheres
//
//  Created by Tyler on 10/15/17.
//
//

#pragma once
#include "ofMain.h"

class Sphere
{
public:
	
	Sphere();
	Sphere(ofVec3f _pos, float _radius);
	~Sphere() {}
	
	void update();
	void draw();
	
	// bounce off walls
	void checkBounds(float x1, float x2, float y1, float y2, float z1, float z2); // left, right, top, bottom, front, back
	
	// color based on pos and bounds
	void colorByBounds(float x1, float x2, float y1, float y2, float z1, float z2);
	
	ofVec3f pos;
	ofVec3f vel;
	
	float radius;
	ofColor color;
};