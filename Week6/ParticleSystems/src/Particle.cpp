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
	lifespan = 3.; // seconds
}

Particle::Particle(ofVec3f _pos)
{
	pos = _pos;
	vel.x = ofRandom(-2, 2);
	vel.y = ofRandom(-1, -5);
	lifespan = 3.;
}

void Particle::applyForce(ofVec3f force){
	acc += force;
}

void Particle::update(float timeDiff){ // how much time has passed since last frame?
	vel += acc;
	pos += vel;
	acc *= 0;
	
	lifespan -= timeDiff;
	if (lifespan < 0.) lifespan = 0.;
}

void Particle::draw(){
	ofPushStyle();
	float hue = ofMap(lifespan, 0., 3., 0, 255);
	ofSetColor(ofColor::fromHsb(hue,hue,hue));
	
	ofDrawCircle(pos, 5);
	ofPopStyle();
}

