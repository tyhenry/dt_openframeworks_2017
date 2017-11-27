#pragma once

#include "ofMain.h"

// BASIC BRUSH CLASS:

class Brush 
{
public:

	Brush() {}

	// we will create an empty draw function for
	// our other brushes to inherit

	// we label this function "virtual"
	// - this means that the inherited versions will override it

	virtual void draw(float x, float y)			// virtual means it will be overridden
	{
		lastDrawPos = ofVec2f(x,y);
		cout << "Brush drawing at " << lastDrawPos << " - size: " << size << ", color: " << color;
	}

	float size		= 10.;
	ofColor color	= ofColor::white;

	ofVec2f lastDrawPos;		// keeps track of the last draw position

};


// CIRCLE BRUSH:

class BrushCircle : public Brush	// inherit from Brush
{
public:

	BrushCircle() {}

	void draw(float x, float y)	override	// overrides the Brush::draw() base function
	{
		if (ofVec2f(x, y).distance(lastDrawPos) >= size)
		{
			Brush::draw(x, y);		// you can call parent classes' functions from the child

			ofPushStyle();
			ofSetColor(0);
			ofDrawCircle(x,y, size+1.f);

			ofSetColor(color);
			ofDrawCircle(x,y, size);
			ofPopStyle();

			cout << " - BrushCircle" << endl;
		}
	}
};


// SQUARE BRUSH:

class BrushSquare : public Brush		// inherit from Brush
{
public:

	BrushSquare() {}

	void draw(float x, float y)	override	// overrides the Brush::draw() base function
	{
		if (ofVec2f(x, y).distance(lastDrawPos) >= 10)
		{
			Brush::draw(x, y);		// you can call parent classes' functions from the child

			ofPushStyle();
			ofSetRectMode(OF_RECTMODE_CENTER);

			ofSetColor(0);
			ofDrawRectangle(x, y, (size+1.f) * 2.f, (size+1.f) * 2.f);

			ofSetColor(color);

			ofDrawRectangle(x, y, size * 2.f, size * 2.f);
			ofPopStyle();

			cout << " - BrushSquare" << endl;
		}
	}
};