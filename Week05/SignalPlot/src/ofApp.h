#pragma once

#include "ofMain.h"

// simple Signal class just contains a current position, and the previous position
// and can draw a line between the two

class Signal {
public:
	Signal()					// constructor
	{
		pos.set(0,0);
		prevPos.set(0,0);
	}
	
	~Signal(){}				// destructor
	
	void update(float x, float y)
	{
		prevPos = pos;
		pos = ofVec2f(x,y);
	}
	
	void draw() {
		ofPushStyle();		// store current global color
		ofSetColor(color);	// set to signal color
		ofDrawLine(prevPos, pos);
		ofPopStyle();		// restore old global color
		
	}
	
	void reset(float x=0, float y=0)
	{
		pos.set(x,y);
		prevPos = pos;
	}
	
	ofVec2f pos;
	ofVec2f prevPos;
	
	ofColor color = ofColor(255);
};

// ofApp

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	Signal sinSig;		// sin wave
	Signal sinHFSig;	// hi-frequency sin wave
	
	Signal amSig;		// amplitude modulated sin wave
	Signal fmSig;		// frequency modulated sin wave
	
	float x = 0;					// current x pos of all signals
	float lastFrameTime = 0;	// track timestamp of last frame
};
