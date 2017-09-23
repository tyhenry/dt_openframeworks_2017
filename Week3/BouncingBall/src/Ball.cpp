#include "Ball.h"

// constructor
Ball::Ball() {

	// inside the constructor you initialize the object's variables

	// random radius between 10 and 50
	radius = ofRandom(10,50);			

	// random color
	float red	= ofRandom(0,255);
	float green	= ofRandom(0,255);		
	float blue	= ofRandom(0,255);
	color = ofColor(red, green, blue);

	// random position in window
	pos.x = ofRandom(radius, ofGetWidth()  - radius);
	pos.y = ofRandom(radius, ofGetHeight() - radius);

	// random x and y speeds/directions between -10 and 10
	dir.x = ofRandom(-10,10);
	dir.y = ofRandom(-10,10);
    
    
}

// update position, etc.
void Ball::update(ofVec2f force) {
    
    acc = force;
    
    dir+=acc;
    pos+=dir;

	// check for bounces at edges of window:

	// check left
	if (pos.x <= radius) {
		pos.x = radius;			// set the position back to the edge of window
		dir.x = -.7 * dir.x;		// and reverse direction
	}
	// check right
	else if (pos.x >= ofGetWidth() - radius) {
		pos.x = ofGetWidth() - radius;			// similar to above
		dir.x = -.7 * dir.x; // slow down
	}

	// check top and bottom
	if (pos.y <= radius) {
		pos.y = radius;
		dir.y = -.7 * dir.y;
	}
	else if (pos.y >= ofGetHeight() - radius) {
		pos.y = ofGetHeight() - radius;
		dir.y = -.7 * dir.y;
	}
}


// draw the ball
void Ball::draw() {

	ofSetColor(color);				// set the GLOBAL color
	ofDrawCircle(pos, radius);		// and draw
}