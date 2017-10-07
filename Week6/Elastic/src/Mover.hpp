//
//  Mover.hpp
//  Attraction
//
//  Created by Tyler on 10/5/17.
//
//

#pragma once
#include "ofMain.h"

class Mover {
	
public:
	
	Mover();
	~Mover(){}
	
	Mover(ofVec3f _pos, float _mass);
	
	void applyForce(ofVec3f force);
	void applyDampingForce(float force);
	void applyElastic();	// elastic brings pos back to origPos
	void checkEdges();		// keep Mover on screen
	
	void update();
	void draw();

	
	ofVec3f origPos, pos, vel, acc;	// store original pos
	float mass;
	
};


