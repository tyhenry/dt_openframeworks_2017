#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup() {
	
	// load the "haar cascade" object description file for
	// default frontal faces:
	finder.setup("haar_cascades/haarcascade_frontalface_default.xml");
	
	finder.setPreset(ObjectFinder::Preset::Fast);
	// also ACCURATE or SENSITIVE

	
	cam.setup(640, 480);
	
}

//--------------------------------------------------------------
void ofApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		
		// update face finder / tracker
		finder.update(cam);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofSetColor(255);
	
	cam.draw(0, 0);
	
	ofNoFill();
	
	for(int i = 0; i < finder.size(); i++) {
		
		ofRectangle face = finder.getObjectSmoothed(i);
		// or get unsmoothed tracker: getObject(i)
		
		
		// draw tracking box
		
		float hue = (float)i/finder.size() * 255.f;
		ofSetColor( ofColor::fromHsb(hue,255,255));
		
		ofDrawRectangle(face);
		
		
		// draw cone hat
						
		ofPushMatrix();
		ofTranslate(face.getCenter() - ofVec2f(0,face.getHeight()));

		cone.set(face.getWidth()*.5, face.getHeight());
		cone.drawWireframe();
		
		ofPopMatrix();
		
		
		// draw number label
		
		ofPushMatrix();
		ofTranslate(face.getPosition());
		ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
		ofPopMatrix();
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
