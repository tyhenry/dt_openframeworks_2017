
#pragma once
#include "ofMain.h"

class Particle {
	
public:

	Particle();
	~Particle(){}
	
	Particle(ofVec3f _pos, ofVec3f _vel);
	
	void applyForce(ofVec3f force);
	void applyDamping(float strength);
	
	void update();
	void draw();
	
	ofVec3f pos, vel, acc;
		
};