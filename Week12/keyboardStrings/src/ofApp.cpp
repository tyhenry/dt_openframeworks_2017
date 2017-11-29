#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(30,10,40);
	
	font.load("LetterGothicStd.otf", 24);	// font file in bin/data/

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	// draw the current input string
	font.drawString(currentString, 500, 100);
	
	
	// draw a list of the saved strings
	
	ofPushMatrix();
	
	ofTranslate(100, ofGetHeight()-50);
	
	for (int i = savedStrings.size()-1; i>=0; i--)
	{
		font.drawString(savedStrings[i], 0, 0);
		ofTranslate(0, -50);
	}
	
	ofPopMatrix();
	
	
	// on-screen instructions
	ofDrawBitmapStringHighlight("type letters and press space", 20,20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	// check if key pressed is in ASCII character ranges A-Z, a-z
	
	if ( (key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))
	{
		// we have a new character
		// add it to current string
		
		currentString += char(key);	// convert to character
	}
	
	else if (key == ' ' || key == OF_KEY_RETURN)	// space or enter/return keys
	{
		// space bar pressed
		
		if (currentString.length() > 0)	// if we've gotten any characters
		{
			savedStrings.push_back(currentString);	// save the string
		}
		currentString = "";	// reset to empty string
	}

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
