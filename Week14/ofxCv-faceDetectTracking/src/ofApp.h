#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"	// include ofxOpenCv when using ofxCv
#include "ofxCv.h"

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
	
	ofVideoGrabber cam;
	ofxCv::ObjectFinder finder;	// our face detector
	
	// ofx::ObjectFinder can find faces, or other things!
	
	// you provide it with an object descriptor file, like
	// "haarcascade_frontalface_default.xml"
	// (finds frontal faces)
	
	// check bin/data for more:
	// - eyes, nose, mouth, license plates, etc.
	
	ofConePrimitive cone;
	
};
