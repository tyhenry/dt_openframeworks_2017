#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	

	// we'll create our movers, and later we'll find their addresses
	
	const int numMovers = 10;
	
	ofVec2f pos;
	pos.x		= ofGetWidth()*.5;
	pos.y		= ofGetWidth()*.5;
	
	for (int i=0; i<numMovers; i++)
	{
		
		float mass		= ofMap(i,0,numMovers,1.,.1);
		
		float ang		= ofMap(i,0,numMovers,0,PI*2.);
		float mag		= ofMap(i,0,numMovers,50,200.);
		ofVec2f vel		= ofVec2f( cos(ang), sin(ang) ) * mag;
		
		movers.push_back( Mover(pos,mass,vel) );
	}
	

}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	for (int i=0; i<movers.size(); i++)
	{
		movers[i].update();
		movers[i].keepInside( ofRectangle( 0,0,ofGetWidth(),ofGetHeight() ) );
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofVec2f mouse;
	mouse.x = ofGetMouseX();
	mouse.y = ofGetMouseY();
	
	for (int i=0; i<movers.size(); i++)
	{
		// draw mover
		movers[i].draw();
		
		// draw pointer as label
		string label = ofToString(&movers[i]);
		ofDrawBitmapStringHighlight(label, movers[i].getPos());
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
