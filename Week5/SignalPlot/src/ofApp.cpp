#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetBackgroundAuto(false); // dont clear background
	
	ofBackground(0);
	
	x = 100;
	
	sinSig.color	= ofColor::cyan;
	sinHFSig.color	= ofColor::magenta;
	amSig.color		= ofColor::magenta;
	fmSig.color		= ofColor::magenta;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	float time	= ofGetElapsedTimef();			// get time in seconds
	
	x += (time - lastFrameTime) * 60.;			// move 60 pixels horizontally per second
	lastFrameTime = time;
	
	
	// plot signals
	
	
	
	// -- sin
	
	float sinTime	= sin (time);	// sin of time
	
	sinSig.update(x, sinTime * 50.);		// -50 to 50 range
	
	
	// -- high-freq sin
	
	float sinHFTime	= sin (time * 20.);		// higher frequency (20 x) sin of time
	
	sinHFSig.update(x, sinHFTime * 50.);
	
	
	// -- amplitude modulated signal
	
	float am			= sin (time * 20.) * sinTime;		// modulate HF sin wave amplitude by sin of time
	
	amSig.update(x, am * 50.);
	
	
	// -- frequency modulated signal
	
	float fm			= sin ( sinTime * 20. );			// modulate frequency by sin of time
	
	fmSig.update(x, fm * 50.);
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	if (x > ofGetWidth()){
		
		ofClear(0); // clear background
		
		x = 100; // reset x position
		
		sinHFSig.reset(x, sinHFSig.pos.y);	// reset signal positions
		sinSig.reset(x, sinSig.pos.y);
		amSig.reset(x, amSig.pos.y);
		fmSig.reset(x, fmSig.pos.y);
		
	}
	
	
	// draw signals
	
	float y = 150;
	
	
	// hi-freq sin of time
	
	ofTranslate(0, y);
	
	sinHFSig.draw();
	
	ofDrawBitmapStringHighlight("sin of (time * 20)", 20, -60, ofColor::black, sinHFSig.color);
	
	
	// sin of time
	
	ofTranslate(0, y);
	
	sinSig.draw();
	
	ofDrawBitmapStringHighlight("sin of time", 20, -60, ofColor::black, sinSig.color);
	
	
	// amplitude modulation
	
	ofTranslate(0, y);
	
	sinSig.draw();
	amSig.draw();
	
	ofDrawBitmapStringHighlight("amplitude modulated: sin(time * 20) * sin(time)", 10, -60, ofColor::black, amSig.color);
	
	
	// frequency modulation
	
	ofTranslate(0, y);
	
	sinSig.draw();
	fmSig.draw();
	
	ofDrawBitmapStringHighlight("frequency modulated: sin( sin(time) * 20 )", 20, -60, ofColor::black, fmSig.color);
	
	
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
