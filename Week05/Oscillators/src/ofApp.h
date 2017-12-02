#pragma once

#include "ofMain.h"


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
	
	// locations to oscillate
	
	ofVec3f sinOsc;
	ofVec3f cosOsc;
	ofVec3f mixOsc; // we'll mix sin and cos oscillation over x and y
	
	float amplitude;
	
	ofPolyline mixTrail; // we'll store the mix values to draw a trail
		
};
