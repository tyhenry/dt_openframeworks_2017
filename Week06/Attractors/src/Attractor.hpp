//
//  Attractor.hpp
//  Attractors
//
//  Created by Tyler on 10/6/17.
//
//

#pragma once
#include "ofMain.h"

#include "Mover.hpp"
// Attractor class will apply attraction force on Movers

class Attractor {
public:
	
	Attractor();		// default constructor
	~Attractor()	{}	// default destructor (empty)
	
	Attractor(ofVec3f _pos, float _mass);	// alternative constructor
	
	ofVec3f getForce(Mover m);
	// calculate attraction (or repulsion!)
	
	void draw();
	
	ofVec3f pos;
	float mass;
	
	const float G = .4;		// gravitational constant
	// affects strength of gravity
	
};
