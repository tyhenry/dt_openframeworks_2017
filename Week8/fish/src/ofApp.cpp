#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(ofColor::blue);

	// let's make our fish - 
	// it will be an ofPolyline, a flexible chain of points
	// (i.e. fish.spine is an ofPolyline)

	// our fish "spine" will be 300 pixels long

	float fishLength	= 300.;	

	int numPoints		= 20;			// fish spine will have 20 "points"/"vertices" spread over the length

	float step			= fishLength / numPoints;	// gap between the points

	// add the points

	for (float i = 0; i < fishLength; i += step ) {
		fish.spine.addVertex( -i, 0);		// place points just on x-axis for simplicity
											// note I'm placing them in negative x-axis, so the head is at 0 and tail is at -300
	}


}

//--------------------------------------------------------------
void ofApp::update(){

	// loop through the fish spine points and add sin wave to y pos

	float time = ofGetElapsedTimef();

	for (int i = 0; i < fish.spine.size(); i++)
	{
		float sinTime	= sin(i * 0.1 + time * 10);		// wave moves down spine over time (0.1 adjusts wave frequency, 10 adjusts animation speed)

		float motionPct = ofMap(i, 0, fish.spine.size(), 0.2, 1.0);	// the head moves less than the tail

		fish.spine[i].y = sinTime * 50 * motionPct;		// -50 to +50 movement on y axis at tail (20% at head)
	}

	fish.pos.set (ofGetMouseX(), ofGetMouseY());

	// we could rotate our fish now based on velocity or whatever, but I'll just set rotation to 0

	// fish.angle = ofRadToDeg( atan2 (fish.vel.y, fish.vel.x) );
	fish.angle = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);

	ofTranslate(fish.pos);	// translate to fish position

	ofRotate(fish.angle);

	fish.spine.draw();

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
