#pragma once

#include "ofMain.h"

// declare simple Arrow class
class Arrow {
	
	public:
		Arrow(){  pos.set(0); }
		~Arrow(){}
		
		void update(ofVec3f p);
		void draw();
		
		ofVec3f pos;
		float angle;
		
	private:
		float myPrivateNumber;
};


// ofApp
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
	Arrow arrow;
		
};
