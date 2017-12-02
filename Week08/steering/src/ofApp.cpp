#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	vehicle.pos.set(0,0);
	
	vehicle.maxForce	= 0.1;
	vehicle.maxSpeed	= 4.0;


}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofVec3f mouse = ofVec3f(ofGetMouseX(), ofGetMouseY());
	vehicle.seek(mouse);
	
	vehicle.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(ofColor::red);
	ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 5);
	
	vehicle.draw();

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
