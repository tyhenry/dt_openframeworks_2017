#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
	
	// our gui ( using ofxGui addon! )
	ofxPanel			gui;		// our visible gui panel
	ofxFloatSlider	scale;		// slider control
	ofxToggle		bNoise;		// noise mesh toggle
	ofxToggle		bRotate;	// auto-rotate mesh toggle
	ofxToggle		bWires;		// draw wireframe toggle
	ofxToggle		bAxis;		// draw scene axis toggle
	
	ofMesh mesh;
	ofEasyCam cam;
	
	ofVideoGrabber vid;
	
	float rotation = 0;
		
};

