#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	amplitude = 300; // this will be the "radius" of our oscillation
	
	sinOsc.set(0, -amplitude);
	cosOsc.set(-amplitude, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	float time = ofGetElapsedTimef();
	
	float sinFrequency = ofMap(ofGetMouseX(), 0, ofGetWidth(), 1., 3.);
	float cosFrequency = ofMap(ofGetMouseY(), 0, ofGetHeight(), 1., 3.);
	
	
	float sinT = sin(time * sinFrequency) * amplitude;
	float cosT = cos(time * cosFrequency) * amplitude;
	

	sinOsc		= ofVec2f(sinT, -amplitude);	// sin oscillates on x

	cosOsc		= ofVec2f(-amplitude, cosT);	// cos oscillates on y
	
	mixOsc = ofVec2f(sinT, cosT);
	
	mixTrail.addVertex(mixOsc);
	if (mixTrail.getVertices().size() > 5000) {
		mixTrail.clear(); // reset
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5);
	
	ofSetColor(ofColor::purple);
	ofSetLineWidth(10);
	mixTrail.draw();
	
	ofSetColor(ofColor::red);
	ofDrawCircle(sinOsc, 5);
	
	ofSetColor(ofColor::blue);
	ofDrawCircle(cosOsc, 5);
	
	if (ofGetMousePressed())
	{
		ofSetLineWidth(2);
		
		ofSetColor(ofColor::red);
		ofDrawLine(mixOsc,sinOsc);
		
		ofSetColor(ofColor::blue);
		ofDrawLine(mixOsc,cosOsc);
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
	
	mixTrail.clear();

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
