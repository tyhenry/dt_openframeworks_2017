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
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (int i=0; i<movers.size(); i++)
	{
		if (i != movers.size() -1)
		{
			ofDrawLine(movers[i].pos, movers[i+1].pos);
		}
		movers[i].draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
