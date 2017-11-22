//
//  Mover.hpp

#pragma once
#include "ofMain.h"

class Mover {
	
public:
	
	// constructor - called when a Mover is created and stored in memory
	Mover();
	Mover(ofVec3f _pos, float _mass, ofVec3f _vel);
	
	// destructor - called when the Mover is deleted and memory is freed
	~Mover() {}

	
	void applyForce(ofVec3f force);
	void applyDampingForce(float force);
	
	void update();
	void keepInside(ofRectangle bounds);	// bounce inside box
	
	void draw();
	
	// check if p is inside Mover radius
	bool isInside(ofVec3f p);
	
	ofVec3f getPos()	{ return pos; }
	
	
private:
	
	ofVec3f pos, vel, acc;
	float mass;
	
	float radius;
	ofColor color;
	
	float lastUpdateTime;
	
};


