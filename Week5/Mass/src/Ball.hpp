//
//  Ball.hpp
//  Mass
//

#pragma once
#include "ofMain.h"

class Ball {
public:
	
	Ball(){}
	~Ball(){}
	
	// extra constructor form with pos and mass:

	Ball(ofVec3f p, float m);	// mass should be on scale of 0 to 10
	
	void applyForce(ofVec3f force); // acceleration += force / mass
	
	void update(); // apply and reset acceleration
	
	void checkWalls(ofRectangle walls); // bounce off walls
	
	void draw();
	void drawDirectionLine();	// private function to draw direction vector

	
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f acc;
	
	float mass;
	float radius;		// we use the mass to set radius and color internally
	ofColor color;
	
	
	
};