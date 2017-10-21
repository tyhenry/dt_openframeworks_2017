#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);

	int numBalls = 5;

	// fill our vector
	for (int i = 0; i < numBalls; i++) {
		balls.push_back(Ball());
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}
	
	// now, take a "screenshot" of the frame
	screenImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());
	
	// resize the screenshot to 10x10 pixels
	
	screenImage.resize(10,10);
	
	
	// sample colors from the screenshot, and draw as a grid overlay:
	
	// overlay opacity based on mouse x
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
	
	ofSetColor(0, alpha);
	ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());	// draw black rect to clear screen
	
	

	int nCols = 10;
	int nRows = 10;
	
	// grid square size for drawing:
	float width = ofGetWidth() / (float)nCols;
	float height = ofGetHeight() / (float)nRows;

	
	for (int y=0; y<nRows; y++) {
		for (int x=0; x<nCols; x++) {
			
			// sample the color of the screenshot at this grid pos
			ofColor color = screenImage.getColor(x,y);
			color.a = alpha;
			
			// draw a rectangle on screen
			
			ofSetColor(color);
			ofDrawRectangle(x * width, y * height, width, height);
		}
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
