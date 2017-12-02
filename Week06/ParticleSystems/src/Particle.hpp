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
	
	Particle(ofVec3f _pos);
	
	void applyForce(ofVec3f force);
	
	void update(float timeDiff); // timeDiff = time elapsed since last frame in seconds
	void draw();
	
	ofVec3f pos, vel, acc;
	
	float lifespan;	// seconds
};