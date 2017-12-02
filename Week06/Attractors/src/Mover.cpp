//
//  Mover.cpp
//  Attraction
//
//  Created by Tyler on 10/5/17.
//
//

#include "Mover.hpp"

Mover::Mover()
{
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());
	
	mass = ofRandom(5,10);
}

Mover::Mover(ofVec3f _pos, float _mass){
	pos = _pos;
	mass = _mass;
}

void Mover::applyForce(ofVec3f force)
{
	// force = mass * acceleration
	// acc = force / mass
	
	acc += force/mass;
}

void Mover::applyDampingForce(float force)
{
	acc -= vel.getNormalized() * force;
	// we use a "normalized" velocity (i.e. magnitude of 1)
	// because damping force should be constant
	// no matter what our velocity's magnitude (speed)
	
}

void Mover::update()
{
	vel += acc;
	pos += vel;
	
	acc *= 0;
}

void Mover::draw()
{
	ofPushStyle();
	float hue = ofMap(mass, 1, 10, 100, 150);
	ofSetColor( ofColor::fromHsb(hue, 255, 250) );
	
	ofDrawCircle(pos, mass);
	
	ofPopStyle();
}





