#include "ofApp.h"

const int width = 100;		// 100 pixels width
const int height = 100;		// 100 pixels height
const int nChannels = 4;	// RGBA color
const int nBytes = width * height * nChannels;

//--------------------------------------------------------------
void ofApp::setup(){
	
	// manually allocate a pixel array

	/*
	 to allocate using ofPixels we would write:
	 
	 ofPixels pixels;
	 pixels.allocate(100,100,OF_IMAGE_COLOR_ALPHA);
	 
	 to manually allocate an array, we write:
	*/
	
	pixelData = new unsigned char[ nBytes ];		// new byte array with "nBytes" # of elements
	
	// log some info to the console on our array:
	
	ofLogNotice() << endl
		<< "allocated pixel array at " << (void*)pixelData << " of size: " << nBytes << " bytes" << endl
		<< width << "x" << height <<" * " << nChannels << " channels";
	
	
	// fill our pixels with noise colors
	
	for (int i=0; i<nBytes; i+=nChannels)		// 4 bytes/channels per pixel
	{
		int x = (i/nChannels) % width;			// pixel x
		int y = (i/nChannels) / width;			// pixel y
		
		ofVec2f pos			= ofVec2f(x,y);
		
		pixelData[i]		= ofNoise(pos * 0.01 + 1000) * 255;	// red		- 1st byte/channel
		pixelData[i+1]		= ofNoise(pos * 0.01 + 2000) * 255;	// green	- 2nd byte/channel
		pixelData[i+2]		= ofNoise(pos * 0.01 + 3000) * 255;	// blue		- 3rd byte/channel
		pixelData[i+3]		= ofNoise(pos * 0.01 + 4000) * 255;	// alpha	- 4th byte/channel
	}

	
	// let's track these pixels using an ofImage
	// the ofImage will store a pointer to our custom pixels
	
	img.getPixels().setFromExternalPixels(pixelData, width, height, nChannels);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// update our pixels with noise colors over time
	
	float time = ofGetElapsedTimef() * .1;
	
	for (int p=0; p<nBytes; p+=nChannels)		// 4 bytes/channels per pixel
	{
		int x = (p/nChannels) % width;			// pixel x
		int y = (p/nChannels) / width;			// pixel y
		
		ofVec2f pos			= ofVec2f(x,y) * 0.01;
		
		pixelData[p]		= ofNoise(pos.x,pos.y, time + 1000) * 255;	// red		- 1st byte/channel
		pixelData[p+1]		= ofNoise(pos.x,pos.y, time + 2000) * 255;	// green	- 2nd byte/channel
		pixelData[p+2]		= ofNoise(pos.x,pos.y, time + 3000) * 255;	// blue		- 3rd byte/channel
		pixelData[p+3]		= ofNoise(pos.x,pos.y, time + 4000) * 255;	// alpha	- 4th byte/channel
	}
	
	img.update();		// update the image texture with the new pixel values


}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	ofPushMatrix();
	ofPushStyle();
	
	float fitScale = ofGetWidth() / (width * 2.);
	ofScale(ofVec3f(fitScale));		// scale to fit 2 images in window
	
	
	// manually draw the pixels:
	
	for (int i=0; i<nBytes; i+=4)		// 4 == numChannels
	{
		// read color at this pixel
		
		ofColor color;
		color.r = pixelData[i];		// offset pointer by i, get value
		color.g = pixelData[i+1];	// offset by i+1
		color.b = pixelData[i+2];
		color.a = pixelData[i+3];
		
		// calculate the x,y position at this byte
		int x = (i/4) % width;
		int y = (i/4) / width;
		
		// draw the pixel as a box
		ofSetColor(color);
		ofDrawRectangle(x,y,1,1);
		
	}
	ofSetColor(255);
	

	// auto-draw the pixels using the image texture:
	
	img.draw(width, 0, width, height);
	
	ofPopStyle();
	ofPopMatrix();	// end scaling
	
	

	// add labels
	
	stringstream pixLabel;
	pixLabel
		<< "pixels: unsigned char [" << nBytes << "] @ " << (void*)pixelData << endl
		<< width << " x " << height << " * " << nChannels << " channels";
	ofDrawBitmapString(pixLabel.str(),20,height*fitScale+20);
	
	stringstream texLabel;
	texLabel
		<< "texture loaded from pixels" << endl
		<< "scaled to " << width * fitScale << " x " << height * fitScale;
	ofDrawBitmapString(texLabel.str(),width*fitScale+20, height*fitScale+20);
	
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	// invert colors when key is pressed
	
//	for (int i=0; i<pix)

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
