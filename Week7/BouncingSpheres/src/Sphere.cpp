//
//  Sphere.cpp
//  BouncingSpheres
//
//  Created by Tyler on 10/15/17.
//
//

#include "Sphere.hpp"

Sphere::Sphere()
{
	pos = ofVec3f();
	
	radius = ofRandom(5,20);
	
	// choose random direction
	
	vel.x = ofRandom(-1,1);
	vel.y = ofRandom(-1,1);
	vel.z = ofRandom(-1,1);
	
	// assign speed based on radius
	
	vel = vel.getNormalized() * ofMap(radius, 5, 20, 4., 1.);
	
	color = ofColor::fromHsb(0, 255, 220);
	color.setHue( ofMap(radius, 5, 20, 100, 200) );
}

Sphere::Sphere(ofVec3f _pos, float _radius)
{
	Sphere(); // default values
	pos = _pos;
	radius = _radius;
}

void Sphere::update()
{
	pos += vel;
	
	// color code based on velocity direction and speed
	
	float xPct = 0;
	float yPct = 0;
	float zPct = 0;
	
	float velSum = abs(vel.x) + abs(vel.y) + abs(vel.z);
	if (velSum != 0)
	{
		xPct = abs(vel.x) / velSum;
		yPct = abs(vel.y) / velSum;
		zPct = abs(vel.z) / velSum;
	}
	
	color.set(55); // minimum brightness
	
	float brt = ofMap( vel.length(), 0., 3., 0, 200, true);	// extra brightness
	
	// add r,g,b based on x,y,z direction and speed
	color.r = color.r + xPct * brt;
	color.g = color.g + yPct * brt;
	color.b = color.b + zPct * brt;
	
}

void Sphere::draw()
{
	ofPushStyle();
	ofSetColor(color);
	ofDrawSphere(pos, radius);
	ofPopStyle();
}

void Sphere::checkBounds(float x1, float x2, float y1, float y2, float z1, float z2)
{
	// check x
	if (pos.x < x1 + radius) {	// left
		pos.x = x1 + radius;
		vel.x *= -1.;
	}
	
	if (pos.x > x2 - radius) {	// right
		pos.x = x2 - radius;
		vel.x *= -1.;
	}
	
	// check y
	if (pos.y < y1 + radius) {	// top
		pos.y = y1 + radius;
		vel.y *= -1.;
	}
	
	if (pos.y > y2 - radius) {	// bottom
		pos.y = y2 - radius;
		vel.y *= -1.;
	}
	
	// check z
	if (pos.z < z1 + radius) {	// front
		pos.z = z1 + radius;
		vel.z *= -1.;
	}
	
	if (pos.z > z2 - radius) {	// back
		pos.z = z2 - radius;
		vel.z *= -1.;
	}
	
}