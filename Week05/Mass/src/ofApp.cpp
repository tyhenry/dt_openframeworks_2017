#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	ofVec3f center = ofVec3f(ofGetWidth()*.5, ofGetHeight()*.5, 0);

	// init ball vector
	
	const int nBalls = 10;

	for (int i=0; i<nBalls; i++)
	{
		float mass = ofMap(i,0,nBalls,10,1);
		Ball ball = Ball(center,mass);
		
		ball.vel = ofVec2f(ofRandom(2), ofRandom(2));
		
		balls.push_back(ball);
	}
	

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// update wind
	
	wind.x = ofSignedNoise(ofGetElapsedTimef() * .1) * .1;
	wind.y = ofSignedNoise(ofGetElapsedTimef() * .1 + 10000) * .1;	// shift time so wind x and y differ
	
	// apply forces to balls
	
	for (int b = 0; b < balls.size(); b++)
	{

		// apply wind
		
		balls[b].applyForce( wind );
	
		// check walls
		
		ofRectangle walls = ofRectangle( 0,0, ofGetWidth(),ofGetHeight() );
		balls[b].checkWalls(walls);
		
		// apply acceleration
		
		balls[b].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor::grey, ofColor::black);
	// gradient backgrounds should be first function of draw()

	for (auto& ball : balls){
		// alternative vector loop format
		
		ball.draw();
	}
	
	// draw wind vector
	
	ofVec3f center = ofVec2f(ofGetWidth()*.5, ofGetHeight()*.5);
	ofDrawCircle( center, 5);
	ofDrawLine( center, center + wind * 1000);

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
