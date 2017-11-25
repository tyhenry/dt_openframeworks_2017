#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	// we're going to find a random point in our application memory
	// and read the data at each byte to fill the screen
	
	bytePtr = new unsigned char;	// pointer to a byte of data in memory
	*bytePtr = 255;					// set the value of this byte to 255
	
	// print the pointer address of the byte
	
	cout << "starting pointer address: " << (void*)bytePtr << endl;
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	ofPushStyle();
	
	// find a range of bytes in memory to draw as a pixel grid

	ofRectangle pixel;
	pixel.setSize(20,20);
	
	int nCols = ofGetWidth() / pixel.width;		// fill the screen with 10x10 "pixel" boxes
	int nRows = ofGetHeight() / pixel.height;
	
	int nBytes	= nCols * nRows;		// number of bytes we'll draw over the grid
	int byteOffset = 0;					// we'll increment this by one for each pixel to get a new byte in memory
	
	for (int row = 0; row < nRows; row++)
	{
		for (int col = 0; col < nCols; col++, byteOffset++)			// increment byteOffset with columns
		{
			
			unsigned char * ptr = bytePtr + byteOffset;		// this byte's address = start address + offset
			
			// get value at this address, value range is 0 - 255
			unsigned char val	= *ptr;
			
			// where to draw this "pixel" on screen
			pixel.x = col * pixel.width;
			pixel.y = row * pixel.height;
			
			// draw as a pixel with brightness of val
			ofSetColor(val);
			ofDrawRectangle(pixel);
			
			if (*ptr < 127)
			{
				// byte is within ASCII range, so draw as text char
				char ch = *ptr;
				ofSetColor(255);
				ofDrawBitmapString( ofToString(ch), pixel.x + 5, pixel.y + pixel.height - 5 );
			}
		}
	}

	ofPopStyle();
	
	
	// let's draw a label for the memory address our mouse is hovering
	
	int col = ofMap(ofGetMouseX(), 0, nCols * pixel.width, 0, nCols, true);
	int row = ofMap(ofGetMouseY(), 0, nRows * pixel.height, 0, nRows, true);
	
	byteOffset = row * nCols + col;					// i = y * width + x
	
	unsigned char *ptr  = bytePtr + byteOffset;		// pointer
	unsigned char val	= *ptr;						// * get value at pointer ("dereference" the pointer)
	
	stringstream label;
	label << (void*)ptr << " -> " << int(val) << " " << ofToString(ptr);
	
	ofSetColor(ofColor::darkBlue);
	ofDrawRectangle(ofGetMouseX(),ofGetMouseY()-20,2,20);
	ofDrawBitmapStringHighlight(label.str(), ofGetMouseX(), ofGetMouseY() - 20, ofColor::darkBlue, ofColor::white);
	
	stringstream cornerLbl;
	cornerLbl << "starting address: " << (void*)bytePtr << "\npress any key to find a new address";
	ofDrawBitmapStringHighlight(cornerLbl.str(), 20,20, ofColor::darkBlue, ofColor::white);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	unsigned char * oldPtr = bytePtr;
	
	int nTries = 0;
	do
	{
		delete bytePtr;
		bytePtr = new unsigned char;
		nTries++;
	}
	while (bytePtr == oldPtr);
	
	cout << "old ptr: " << (void*)oldPtr << " -> new ptr: " << (void*)bytePtr << " - took " << nTries << " tries to find a new allocation" << endl;
	

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
