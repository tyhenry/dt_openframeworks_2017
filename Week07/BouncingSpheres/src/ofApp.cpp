#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(60.f);
	ofBackground(0);
	
	// make the spheres
	
	const int nSpheres = 1000;
	
	for (int i=0; i<nSpheres; i++)
	{
//		float pct = (float)i/nSpheres;
//		Sphere sphere;
//		sphere.vel.x = sin (pct * TWO_PI) * pct * 5.;
//		sphere.vel.y = cos (pct * TWO_PI) * pct * 5.;
//		sphere.vel.z = sin (pct * TWO_PI * 20.f) * pct * 5.;
//		sphere.radius = 10;
//		spheres.push_back(sphere);
		
		spheres.push_back(Sphere());
		
	}
	
	// define the bounding box
	
	bounds.left		= -500.;	// x
	bounds.right		= 500.;
	bounds.top		= -500.;	// y
	bounds.bottom	= 500.;
	bounds.front		= -500.;	// z
	bounds.back		= 500.;

}

//--------------------------------------------------------------
void ofApp::update(){
	
	for (int i=0; i<spheres.size(); i++)
	{
		spheres[i].update();
		spheres[i].checkBounds(bounds.left, bounds.right, bounds.top, bounds.bottom, bounds.front, bounds.back);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	camera.begin();
	ofEnableDepthTest();
	
	ofFill();
	for (int i=0; i<spheres.size(); i++)
	{
		spheres[i].draw();
	}
	
	// draw the bounds
	
	/*
	 a box:
	 
			    +--------+
	           /|       /|
			  / |      / |
			 +--------+  |
		     |  +-----|--+
			 | /      | /
			 |/       |/
	         +--------+
	 
	*/
	
	ofNoFill();
	
	ofDrawBox( bounds.getCenter(), bounds.getWidth(), bounds.getHeight(), bounds.getDepth() );
	ofDrawAxis( 100 );
	
	ofDisableDepthTest();
	camera.end();
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
