
#include "Particle.hpp"

Particle::Particle()
{
}

Particle::Particle(ofVec3f _pos, ofVec3f _vel)
{
	pos = _pos;
	vel = _vel;
}

void Particle::applyForce(ofVec3f force)
{
	acc += force;
}

void Particle::applyDamping(float strength)
{
	acc -= vel.getNormalized() * strength;
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
}

void Particle::draw(){
	
	ofDrawCircle(pos, 1);
}

