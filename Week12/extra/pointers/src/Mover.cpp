//
//  Mover.cpp

#include "Mover.hpp"

// constructors

Mover::Mover()
: Mover( ofVec3f(), 1., ofVec3f() )			// call alt c'tor by default
{
}

Mover::Mover( ofVec3f _pos, float _mass, ofVec3f _vel )
 : pos(_pos), mass(_mass), vel(_vel)		// initializer list syntax
{
	// calc radius and color from mass
	radius		= mass * 50.;
	float hue	= ofMap(mass, .5, 2, 130, 230);
 	color		= ofColor::fromHsb(hue, 255, 255);
	
	lastUpdateTime	= ofGetElapsedTimef();
}


void Mover::applyForce(ofVec3f force)
{
	// force = mass * acc
	
	acc += force/mass;
}

void Mover::applyDampingForce(float force)
{
	acc += -vel.getNormalized() * force;
	// we use "normalized" inverse velocity (i.e. magnitude of -1)
}

void Mover::update()
{
	vel += acc;
	
	float timeDiff = ofGetElapsedTimef() - lastUpdateTime;
	
	pos += vel * timeDiff;
	
	acc *= 0;
	
	lastUpdateTime	= ofGetElapsedTimef();
}

void Mover::keepInside(ofRectangle bounds)
{
	// keep mover in 2D bounds (bounce)

	if (pos.x < bounds.getLeft()) {
		pos.x = bounds.getLeft();
		vel.x *= -1;
	}

	if (pos.x > bounds.getRight()) {
		pos.x = bounds.getRight();
		vel.x *= -1;
	}

	if (pos.y < bounds.getTop()) {
		pos.y = bounds.getTop();
		vel.y *= -1;
	}

	if (pos.y > bounds.getBottom()) {
		pos.y = bounds.getBottom();
		vel.y *= -1;
	}
}

void Mover::draw()
{
	ofPushStyle();
	
	ofSetColor(color);
	ofDrawCircle(pos, radius);
	
	ofPopStyle();
}

bool Mover::isInside(ofVec3f p)
{
	// check if p is inside Mover radius
	return (pos.distance(p) <= radius);
}





