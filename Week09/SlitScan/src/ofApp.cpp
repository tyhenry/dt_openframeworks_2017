#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	
	cam.listDevices();		// prints all your cameras to console

	cam.setup(640, 480);	// start default cam
	
	fbo.allocate(640, 480);		// "drawing space" offscreen
	
	lineNum = 0;		// track which line of webcam image we're drawing
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	cam.update();	// update web cam
	
		
	fbo.begin();		// draw offscreen
	
	ofTexture tex = cam.getTexture();
	
	// draw a single line from the webcam image
	tex.drawSubsection
	(
		0, lineNum, 640, 1,	// draw area (x,y,w,h)
		0, lineNum, 640, 1  // source area
	 );
	
	fbo.end();
		
	
	lineNum = (lineNum+1) % 480;
	// increment lineNum by 1 - and at 480, reset to 0

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	fbo.draw(0,0, ofGetWidth(), ofGetHeight());	// draw our buffer

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
