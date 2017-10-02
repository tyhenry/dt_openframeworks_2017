#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	// make a grid of 10x10 squares
	
	for (int x=0; x<ofGetWidth(); x+=10){
		
		for (int y=0; y<ofGetHeight(); y+=10){
				
				// store the top left corner
				grid.push_back(ofVec3f(x,y));
		}
	}


}

//--------------------------------------------------------------
void ofApp::update(){
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	float noiseScale = ofMap(ofGetMouseX(), 0, ofGetWidth(), .01, .0001);
	
	float timeScale = ofMap(ofGetMouseY(), 0, ofGetHeight(), .1, 1.);
	
	for (int i=0; i<grid.size(); i++){
		
		ofVec3f coords;
		
		coords.x = grid[i].x * noiseScale;
		coords.y = grid[i].y * noiseScale;
		
		coords.z = ofGetElapsedTimef() * timeScale;
			
		float noise = ofNoise(coords);
		
		
		int hue = noise * 100 + 155;	// purple to red hue
		int sat = noise * 100 + 155;	// half to full saturation
		int brt = noise * 200 + 55;		// low to high brightness
		
		ofSetColor(ofColor::fromHsb(hue,sat,brt));
		
		ofDrawRectangle(grid[i], 10, 10);
		
	}
	
	// draw label
	
	string line1 = "mouse x: scale";
	string line2 = "mouse y: speed";
	string label = line1 + "\n" + line2; // "\n" adds a line break
	ofDrawBitmapStringHighlight(label, 20, 20);

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
