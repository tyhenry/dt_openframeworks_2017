#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	camW = 640;
	camH = 480;
	
	webcam.setup(camW, camH);
	
	// we are going to copy the red green and blue channels
	// from the camera into separate images
	
	// we should pre-allocate our images
	
	red.allocate(camW, camH, OF_IMAGE_COLOR);
	green.allocate(camW, camH, OF_IMAGE_COLOR);
	blue.allocate(camW, camH, OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	webcam.update();
	
	if (webcam.isFrameNew())
	{
		// loop through pixels
		for (int y=0; y<webcam.getHeight(); y++) {
			for (int x=0; x<webcam.getWidth(); x++) {
				
				// grab the pixel color at x,y
				ofColor color = webcam.getPixels().getColor(x,y);
				
				// separate color channels
				
				if (bInvert) {
					color.r = 255-color.r;
					color.g = 255-color.g;
					color.b = 255-color.b;
				}
				
				red.setColor(x,y, ofColor(color.r, 0, 0));
				green.setColor(x,y, ofColor(0, color.g, 0));
				blue.setColor(x,y, ofColor(0, 0, color.b));
				
			}
		}
		
		// copy pixels to textures so we can draw them onscreen
		
		red.update();
		green.update();
		blue.update();

	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// draw images and rectangles with center as origin
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	// draw using add overlay effect
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	
	// spread the channels on screen
	
	ofVec2f center = ofVec2f(ofGetWidth()*.5, ofGetHeight()*.5);
	ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
	
	ofVec2f offset = center - mouse;
	
	ofPushMatrix();
	ofTranslate(center);
	
	red.draw(-offset);
	
	green.draw(0,0);
	
	blue.draw(offset);
	
	ofPopMatrix();
	
	
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);	// return to default alpha blending
	
	ofSetRectMode(OF_RECTMODE_CORNER);
	stringstream ss;
	ss << "press any key to invert [" << bInvert << "]";
	ofDrawBitmapStringHighlight(ss.str(), 20,20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	bInvert = !bInvert;

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
