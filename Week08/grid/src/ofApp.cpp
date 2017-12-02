#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	// define our grid dimensions:
	nCols = 8;
	nRows = 8;

	int gridSize = nCols * nRows;
	
	// initialize the grid
	for (int i=0; i < gridSize; i++)
	{
		grid.push_back(ofColor(255));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
	for (int y=0; y<nRows; y++)
	{
		for (int x=0; x<nCols; x++)
		{
		
			// noise based on grid position
			
			ofVec3f noisePos;
			noisePos.x = x * .1;
			noisePos.y = y * .1;
			
			// hue noise
			noisePos.z = ofGetElapsedTimef() * .5;
			float hue = ofNoise( noisePos ) * 255.;
			
			// brightness noise
			noisePos.z = ofGetElapsedTimef() * .5 + 1000.;
			float brt = ofNoise( noisePos ) * 255.;
			
			// assign color to grid
			int i = y * nCols + x;	// get grid index from x,y
			
			grid[i].setHsb(hue, 255, brt);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// figure out draw size so grid fills window
	float xRes = ofGetWidth()/float(nCols);
	float yRes = ofGetHeight()/float(nRows);
	
	
	// draw color grid to look like a LED grid
	for (int y=0; y<nRows; y++)
	{
		for (int x=0; x<nCols; x++)
		{
			
			int i = y * nCols + x;
			ofSetColor( grid[i] );
			
			ofVec2f pos;
			pos.x = xRes * (x + .5);	// + .5 centers the dot
			pos.y = yRes * (y + .5);	// in the grid square
			
			ofDrawCircle(pos, 3);
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
