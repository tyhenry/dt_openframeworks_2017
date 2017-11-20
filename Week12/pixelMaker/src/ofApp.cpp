#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	pixels.allocate(5,5,OF_IMAGE_COLOR_ALPHA);
	
	// fill a 5 x 5 ofPixels object with random colors
	// by looping through the pixel data:
	
	for (int i=0; i<pixels.getTotalBytes(); i+=4)	// 4 bytes/channels per pixel
	{
		pixels[i]		= ofRandom(255);	// red		- 1st byte/channel
		pixels[i+1]		= ofRandom(255);	// green	- 2nd byte/channel
		pixels[i+2]		= ofRandom(255);	// blue		- 3rd byte/channel
		pixels[i+3]		= 255;				// alpha	- 4th byte/channel
	}


}

//--------------------------------------------------------------
void ofApp::update(){
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// we'll now access the ofPixels using a pointer to the raw data -
	
	// this is SAME as looping through pixels[i], like in setup()
	// just using a different syntax!
	
	
	for (int i=0; i<pixels.getTotalBytes(); i+=4)
	{
		
		unsigned char * pixData = pixels.getData() + i;

		// read color at this pixel
		ofColor color;
		color.r = pixData[0];		// offset pointer by 0, and dereference
		color.g = pixData[1];		// offset by 1
		color.b = pixData[2];
		color.a = pixData[3];
		
		// calculate the x,y position at this byte
		int x = (i/4) % pixels.getWidth();
		int y = (i/4) / pixels.getWidth();
		
		// draw the pixel as a large box
		ofSetColor(color);
		ofDrawRectangle(x*200,y*100,200,100);
		
		// draw label with pointer addresses and values
		stringstream label;
		label
			<< "address: " <<(void *)(pixData) << endl	// hack to print raw hex
			<< " [0] " << (int)color.r << "\t(r)\n"
			<< " [1] " << (int)color.r << "\t(g)\n"
			<< " [2] " << (int)color.r << "\t(b)\n"
			<< " [3] " << (int)color.r << "\t(a)";

		ofDrawBitmapStringHighlight(label.str(), x*200+20, y*100+20);
		
	}
	ofSetColor(255);
	
	
	

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
