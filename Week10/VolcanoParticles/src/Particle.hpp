//
//  Particle.hpp
//  ParticleSystem
//
//  Created by Tyler on 10/5/17.
//
//

#pragma once
#include "ofMain.h"

class Particle {
	
public:

	Particle();
	~Particle(){}
	
	Particle(ofVec3f _pos, ofVec3f _vel, float _life, float _mass);
	
	void applyForce(ofVec3f force);
	void applyDrag(float amt);
	
	void update();
	void draw();
	
	ofVec3f pos, vel, acc;
	
	float age = 0; // seconds
	
	float lifespan;	// seconds
	
	float mass;
	

private:
	
	ofMaterial material;	// shininess
	
	float lastUpdateTime = 0;	// track elapsed time
	
};