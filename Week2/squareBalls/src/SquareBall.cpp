#include "SquareBall.h"

SquareBall::SquareBall() {

	// nothing needed here, because all variables are initialized in parent Ball class
}

void SquareBall::draw() {
	
	ofSetColor(color);	// the color carries over from the parent Ball class

	float sqX = x - radius; // rectangles draw from the top left corner unlike circles (which draw from the center), so we need to compensate
	float sqY = y - radius;
	ofDrawRectangle(sqX, sqY, radius * 2, radius * 2);  // width and height will both be double the radius
}

