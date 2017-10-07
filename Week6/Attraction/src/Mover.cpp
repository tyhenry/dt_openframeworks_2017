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
	pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	
	mass = ofRandom(5,20);
}

Mover::Mover(ofVec3f _pos, float _mass)
{
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
	
}

void Mover::update()
{
	vel += acc;
	pos += vel;
	
	acc *= 0;
}

void Mover::draw()
{
	ofPushMatrix();
	ofTranslate(pos);
	
	ofDrawCircle(0,0, mass*2.);
	
	ofPopMatrix();
}





