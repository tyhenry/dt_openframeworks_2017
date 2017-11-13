#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	// setup webcam
	vid.setup(640,480);
	
	// allocate the fbo memory
	fbo.allocate(640,480,GL_RGBA);
	
	// clear the fbo's pixels (removes junk data):
	//	fbo.begin();
	//	ofClear(0,0,0,0);
	//	fbo.end();
	
	fboTime = ofGetElapsedTimef();
	
	
	blendmode = OF_BLENDMODE_ADD;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	vid.update();
	
	
	// every 5 seconds, reset the fbo with the latest webcam image
	
	if (ofGetElapsedTimef() - fboTime >= 5)
	{
		fbo.begin();
		vid.draw(0,0,640,480);
		fbo.end();
		
		fboTime = ofGetElapsedTimef();	// reset timer
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	fbo.draw(0,0);	// draw captured webcam frame
	
	
	
	ofEnableBlendMode(blendmode);			// SET TO CUSTOM BLENDMODE
	
	vid.draw(0,0);	// draw current webcam frame on top, with alpha blending
	
	
	// draw red circle with alpha
	ofPushStyle();
	ofSetColor(255,0,0, 122);
	ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 100);
	ofPopStyle();
	
	
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);	// RESET TO DEFAULT ALPHA BLENDMODE FOR OTHER OPERATIONS
	

	
	
	// draw the blend mode instructions on screen
	
	stringstream ss;
	ss << "choose blendmode: 1 - ADD, 2 - SUBTRACT, 3 - MULTIPLY, 4 - SCREEN, 5 - DEFAULT (ALPHA), 6 - DISABLED" << "\n\n";
	string modeStr;
	switch (blendmode) {
		case OF_BLENDMODE_ADD:			modeStr = "ADD"; break;
		case OF_BLENDMODE_SUBTRACT:		modeStr = "SUBTRACT"; break;
		case OF_BLENDMODE_MULTIPLY:		modeStr = "MULTIPLY"; break;
		case OF_BLENDMODE_SCREEN:		modeStr = "SCREEN"; break;
		case OF_BLENDMODE_ALPHA:		modeStr = "DEFAULT (ALPHA)"; break;
		case OF_BLENDMODE_DISABLED:		modeStr = "DISABLED"; break;
	}
	ss << "current blendmode: " << modeStr;
	ofDrawBitmapStringHighlight(ss.str(), 20,500);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	switch (key) {
		case '1':		blendmode = OF_BLENDMODE_ADD; break;
		case '2':		blendmode = OF_BLENDMODE_SUBTRACT; break;
		case '3':		blendmode = OF_BLENDMODE_MULTIPLY; break;
		case '4':		blendmode = OF_BLENDMODE_SCREEN; break;
		case '5':		blendmode = OF_BLENDMODE_ALPHA; break;
		case '6':		blendmode = OF_BLENDMODE_DISABLED; break;
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
