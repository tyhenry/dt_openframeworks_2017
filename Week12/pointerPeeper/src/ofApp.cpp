#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	byte = new unsigned char;	// byte is a pointer to char
	
	for (int i=0; i<300; i++)
	{
		byte[i] = 255;
	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	string label = "";
	ofVec2f labelPos;
	
	for (int y=0; y<ofGetHeight(); y+=10)
	{
		for (int x=0; x<ofGetWidth(); x+=10)
		{
			ofPushStyle();

			int byteOffset = y * ofGetWidth() + x;
			
			// get pointer at this address
			unsigned char * ptr = byte + byteOffset;
			
			// get value at this memory address
			unsigned char val = *ptr;
			ofSetColor(val);
			
			ofRectangle rect = ofRectangle(x,y,10,10);
			ofDrawRectangle(rect);
			
			// if mouse is hovering this rectangle, print pointer address
			if (rect.inside(ofGetMouseX(), ofGetMouseY()))
			{
				label		= ofToString(ptr);
				labelPos	= ofVec2f(x,y+10);
			}
			
			ofPopStyle();
		}
	}
	
	if (!label.empty())
	{
		ofDrawBitmapStringHighlight(label, labelPos);
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
