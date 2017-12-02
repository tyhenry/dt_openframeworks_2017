#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	// make a spiral
	
	ofVec2f center;
	center = ofGetWindowSize() * .5;
	
	int nRotations	= 20;
	float maxAngle	= TWO_PI * nRotations;

	for (float theta = 0.; theta < maxAngle; theta += .1)	// increase angle (in radians)
	{
		
		float radius = (theta / maxAngle) * ofGetWidth() * .5;
		
		ofVec2f pos;
		pos.x = center.x + (cos(theta) * radius);
		pos.y = center.y + (sin(theta) * radius);
	
		Mover mover(pos, 1.);
		movers.push_back(mover);
		
	}
	
	bSpin = false;

}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
	
	for (int i=0; i<movers.size(); i++)
	{
		ofVec2f diff = mouse - movers[i].pos;
		float dist = diff.length();
		
		if (dist < 100.)
		{
			ofVec2f repulsion = diff.getNormalized() * -.5;
			movers[i].applyForce(repulsion);
		}
		
		movers[i].applyElastic();
		
		movers[i].applyDampingForce(0.05);
		
		movers[i].update();
		
		
		
		// add a circular spin (rotate the mover's orig pos and pos)
		
		float rotRad = .05;
		
		if (bSpin)
		{
			ofVec2f center	= ofGetWindowSize()*.5;
			
			// rotate origPos of Mover
			
			ofVec2f oVec	= movers[i].origPos - center;
			float oTheta	= atan2(oVec.y, oVec.x) - rotRad;
			float oRadius	= oVec.length();
			
			movers[i].origPos.x = center.x + (cos(oTheta) * oRadius);
			movers[i].origPos.y = center.y + (sin(oTheta) * oRadius);
			
			// rotate pos of Mover
			
			ofVec2f vec		= movers[i].pos - center;
			float theta		= atan2(vec.y, vec.x) - rotRad;
			float radius	= vec.length();
			
			movers[i].pos.x = center.x + (cos(theta) * radius);
			movers[i].pos.y = center.y + (sin(theta) * radius);
			
		}
		
		
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor::indigo, ofColor::orchid);
	
	for (int i=0; i<movers.size(); i++)
	{
		if (i != movers.size() -1)
		{
			ofDrawLine(movers[i].pos, movers[i+1].pos);
		}
		movers[i].draw();
	}
	
	// draw labels
	
	ofColor lblCol(0); // black
	if (bSpin) lblCol = ofColor::darkRed;
	ofDrawBitmapStringHighlight("space: toggle spin", ofVec2f(20,20), lblCol);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	if (key == ' ')
	{
		bSpin = !bSpin;	// toggle wind
	}

}
