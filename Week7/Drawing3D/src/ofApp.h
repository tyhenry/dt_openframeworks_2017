#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	
	vector<ofPolyline> ribbons;
	
	bool bMakingRibbon;
	
	float zSpeed;
		
};
