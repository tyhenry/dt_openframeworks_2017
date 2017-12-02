#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	mover1.mass = 10.;
	mover2.mass = 15.;

}

//--------------------------------------------------------------
void ofApp::update(){

	ofVec3f mousePos = ofVec3f(ofGetMouseX(), ofGetMouseY());
	
	float attractionStrength = 0.01;
	float dampingStrength = 0.1;
	
	// update mover 1 - small mass
	
	ofVec3f dir1 = mousePos - mover1.pos;	// mouse is target
	
	ofVec3f attraction1 = dir1 * attractionStrength;
	
	mover1.applyForce(attraction1);
	mover1.applyDampingForce(dampingStrength);
	mover1.update();
	
	// update mover 2 - large mass
	
	ofVec3f dir2 = mousePos - mover2.pos;	// mouse is target
	ofVec3f attraction2 = dir2 * attractionStrength;
	
	mover2.applyForce(attraction2);
	mover2.applyDampingForce(dampingStrength);
	mover2.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	mover1.draw();
	mover2.draw();
	
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
