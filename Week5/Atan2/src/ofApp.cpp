#include "ofApp.h"

void Arrow::update(ofVec3f target){
	
	pos = pos * .97 + target * .03;		// interpolate 3% to target
	
	ofVec3f dir = target - pos;			// direction vector
	
	float rad = atan2(dir.y, dir.x);	// gives angle of dir vector in radians
	
	angle = ofRadToDeg(rad);			// convert radians to degrees
}

void Arrow::draw(){
	
	ofVec3f p1 = ofVec3f(0,0);			// front pt
	ofVec3f p2 = p1 - ofVec3f(30,10);	// back pt 1
	ofVec3f p3 = p1 - ofVec3f(30,-10);			// back pt 2
	
	ofPushMatrix();
	
	ofTranslate(pos);
	ofRotate(angle);
	
	ofDrawTriangle(p1,p2,p3);
	
	ofPopMatrix();
	
}
//--------------------------------------------------------------
// end Arrow class definitions


// begin ofApp definitions
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	arrow.update(ofVec3f(ofGetMouseX(),ofGetMouseY()));	// set target to mouse pos
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	arrow.draw();
	
	
	// draw axes
	
	ofVec3f mousePos = ofVec3f(ofGetMouseX(), ofGetMouseY());
	
	ofSetColor(ofColor::red);
	ofDrawLine( arrow.pos, ofVec3f(ofGetWidth(), arrow.pos.y));	// x-axis
	
	ofSetColor(ofColor::green);
	ofDrawLine( arrow.pos, ofVec3f(arrow.pos.x, ofGetHeight())); // y-axis (points down!)
	
	// draw arrow vector
	
	ofSetColor(ofColor::lightBlue);
	ofDrawLine( mousePos, arrow.pos);							// direction vector
	
	// angle arc
	
	ofPolyline arc;
	arc.arc(arrow.pos, 75, 75, 0, arrow.angle, true);
	arc.draw();
	
	// angle labels
	
	float angle360 = arrow.angle;
	if (angle360 < 0) angle360 = 360 + angle360; // shift negative degrees to 0-360 range
	
	string degLbl = ofToString(angle360, 1) + " degrees";
	string radLbl = ofToString(ofDegToRad(angle360) / PI, 2) + " PI radians";
	
	ofDrawBitmapString( degLbl, arrow.pos + ofVec2f(75, 75));
	ofDrawBitmapString( radLbl, arrow.pos + ofVec2f(75, 90));
	
	ofSetColor(255);
}




