#pragma once

#include "ofMain.h"
#include "FlowField.hpp"
#include "Particle.hpp"

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
	
	FlowField flowField;
	vector<Particle> particles;
	
	bool bDrawTrails;
	bool bDrawField;
	bool bDrawImage;
	
	float damping;
	
	ofImage image;
};
