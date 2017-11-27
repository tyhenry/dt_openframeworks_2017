#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);

	ofSetBackgroundAuto(false);

	circleBrush.color = ofColor::pink;
	squareBrush.color = ofColor::aqua;

	activeBrush		= &circleBrush;		// set active brush pointer to circle brush address

}

//--------------------------------------------------------------
void ofApp::update(){

	float time = ofGetElapsedTimef();

	// update the active brush's size and color
	if (activeBrush != nullptr)		// if brush pointer is valid, necessary check when using pointers!
	{
		activeBrush->size	= 10.f + ofNoise(time) * 20.f;
		activeBrush->color.setHue( ofNoise(time) * 255.f );
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (ofGetMousePressed())
	{
		// since we use a pointer for activeBrush
		// and Brush class has a "virtual" draw function...

		// the draw function we call here will be the inherited
		// version in BrushCircle or BrushSquare class

		activeBrush->draw(ofGetMouseX(), ofGetMouseY());
	}

	ofDrawBitmapStringHighlight("press 1 - circle, press 2 - square", 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == '1')
	{
		activeBrush = &circleBrush;	// set pointer to circleBrush address
	}
	else if (key == '2')
	{
		activeBrush = &squareBrush;	// set pointer to squareBrush address
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
