//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Tyler on 10/5/17.
//
//

#include "Particle.hpp"

Particle::Particle()
{
	pos			= ofVec3f();
	vel.x		= ofRandom(-1,1);
	vel.y		= ofRandom(-1,1);
	vel.z		= ofRandom(-1,1);
	lifespan		= ofRandom(5,10); // seconds
	mass			= ofRandom(1,3);
	lastUpdateTime = ofGetElapsedTimef();
}

Particle::Particle(ofVec3f _pos, ofVec3f _vel, float _life, float _mass)
{
	pos			= _pos;
	vel			= _vel;
	lifespan		= _life;
	mass			= _mass;
	lastUpdateTime = ofGetElapsedTimef();
}

void Particle::applyForce(ofVec3f force)
{
	acc += force / mass;
}

void Particle::applyDrag(float amt)
{
	acc -= vel.getNormalized() * amt;
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
	
	float timeDiff = ofGetElapsedTimef() - lastUpdateTime;
	age += timeDiff;
	lastUpdateTime = ofGetElapsedTimef();
}

void Particle::draw()
{
	ofPushStyle();
	
	ofColor fire		= ofColor(255, 120, 0);
	ofColor smoke	= ofColor(34, 32, 30);

	float lerp		= ofClamp(age/lifespan, 0, 1);
	ofColor color	= fire.lerp( smoke, lerp);
	ofSetColor( color );
	
	material.setEmissiveColor( color );
	material.begin();
	
	float radius		= ofMap(age, 0, lifespan, 1, 15);
	
	ofDrawSphere(pos, radius);
	
	material.end();
	
	ofPopStyle();
}

