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
	
	// see bin/data/ for shader code!
	
	ofShader shaderMask;	// use one texture to mask another
	ofShader shaderBrcosa;	// brightness, contrast, saturation
	
	// we'll use the shaders to modify webcam image
	
	ofVideoGrabber webcam;
	ofImage imgMask;		// brightness
	
	// view in 3D!
	ofEasyCam easyCam;
	
	ofPlanePrimitive plane;
};
