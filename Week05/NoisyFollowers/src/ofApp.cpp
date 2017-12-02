#include "ofApp.h"

//--------------------------------------------------------------
// Arrow class definitions:
//--------------------------------------------------------------

void Arrow::update(ofVec3f target){
	
	ofVec3f offsetTarget = target + offset;
	
	pos = pos * (1.-lerp) + offsetTarget * lerp; // move "lerp" % to target
	
	
	ofVec3f direction = target - pos;
	
	float radians = atan2(direction.y, direction.x);
	// atan2 returns angle in radians
	
	angle = ofRadToDeg(radians);	// convert radians to degrees
	
	
}

//--------------------------------------------------------------
void Arrow::draw(){
	
	// triangle
	ofVec3f p1 = ofVec3f(0);	// front
	ofVec3f p2 = p1 - ofVec3f(size * 3, size);	// rear pt 1
	ofVec3f p3 = p1 - ofVec3f(size * 3, -size);	// rear pt 2
	
	ofPushMatrix();
	
	ofTranslate(pos);
	ofRotate(angle);
	
	ofPushStyle();
	ofSetColor(color);
	
	ofDrawTriangle(p1,p2,p3);
	
	ofPopStyle();
	
	ofPopMatrix();
	
}

//--------------------------------------------------------------
// end Arrow class definition
//--------------------------------------------------------------

//--------------------------------------------------------------
// ofApp definitions:
//--------------------------------------------------------------

void ofApp::setup(){
	
	ofBackground(0);
	
	int nArrows = 100;
	
	for (int i=0; i<nArrows; i++){
		
		Arrow arrow;
		
		arrow.pos = ofVec2f( 0 );
		
		arrow.lerp = ofMap(i, 0, nArrows, .008, .04);	// set interpolation "speed", slow to fast
		arrow.size = ofMap(i, 0, nArrows, 5, 1);		// set size, large to small
		
		float hue = ofMap(i, 0, nArrows, 155, 255);		// blue to red
		arrow.color = ofColor::fromHsb(hue, 255, 220);	// hue, saturation, brightness
		
		arrows.push_back(arrow);
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofVec3f target;
	target.set(ofGetMouseX(), ofGetMouseY());
	
	
	for (auto& arrow : arrows){	// alternative syntax for looping through vector
		
		// signed noise has range -1 to 1

		float freq	 = 10. * arrow.lerp;
		float noiseX = ofSignedNoise(ofGetElapsedTimef() * freq);
		float noiseY = ofSignedNoise((ofGetElapsedTimef() + 2000) * freq);
		
		arrow.offset = ofVec3f(noiseX * 400, noiseY * 400);
		
		arrow.update(target);
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (auto& arrow : arrows) {
		
		arrow.draw();
		
		if (ofGetMousePressed()){
			ofSetColor(arrow.color);
			ofDrawLine(arrow.pos, ofVec2f(ofGetMouseX(), ofGetMouseY()));
		}
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
