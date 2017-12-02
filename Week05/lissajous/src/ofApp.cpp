#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//set origin 0,0 to center of the screen
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	
	//LISSAJOUS EXAMPLE
	//http://en.wikipedia.org/wiki/Lissajous_curve
	
	ofSetColor(0);
	
	//Lets make the curves out of a series of points
	
	ofPolyline line;
	

	// the frequencies will represent the # of times the curve "bends" in x and y
	
	float xFreq = ofMap( ofGetMouseX(), 0, ofGetWidth(), 0, 100);		// x frequency is tied to mouse x
	float yFreq = ofMap( ofGetMouseY(), 0, ofGetHeight(), 0, 100);		// y frequency is tied to mouse y

	
	// add 1000 points to line
	
	for(int i = 0; i < 1000; i++){
		
		// figure out the percent of this point on the line
		
		float pct = float(i) / 1000.;
		
		// find the x and y of the point based on the sin and cos
		
		float x =  sin( pct * xFreq ) * 200.;	// sin gives (-1, 1) range, so multiply by 1/2 "box" dimensions
		float y =  cos( pct * yFreq ) * 150.;
		
		line.addVertex(x,y);	// add this point to the curve
	}
	
	// here we draw the curve
	
	line.draw();

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
