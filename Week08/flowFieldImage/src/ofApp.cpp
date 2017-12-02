#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(255);
	ofSetBackgroundAuto(false);
	
	image.load("image.jpg");	// image.jpg is in "bin/data/" folder
	
	// create the flow field at image size, 20 px resolution
	flowField = FlowField(image.getWidth(), image.getHeight(), 20.);
	
	// initialize the flows per the image brightness values
	flowField.initFromImage(image, 0.1);
	
	// make a bunch of particles
	for (int i=0; i<50000; i++){
		
		Particle p;
		p.pos.x = ofRandom(0, ofGetWidth());
		p.pos.y = ofRandom(0, ofGetHeight());
		
		particles.push_back(p);
	}
	
	// settings
	damping = 0.05;
	
}

//--------------------------------------------------------------
void ofApp::update(){

	
	for (int i=0; i<particles.size(); i++)
	{
		// get the force at the particle position
		ofVec3f force = flowField.getForceAt(particles[i].pos);
		
		particles[i].applyForce(force);
		particles[i].applyDamping(damping);
		
		particles[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(0,3);
	for (int i=0; i<particles.size(); i++)
	{
		particles[i].draw();
	}
	
	// draw the text labels
	
	string label =	"press ' ' : reset particle positions \n";
	label +=			"'UP'/'DN' : damping = " + ofToString(damping);
	ofDrawBitmapStringHighlight(label, 20,20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	if (key == ' ')
	{
		// ' ' (space) reset particle positions
		
		for (int i=0; i<particles.size(); i++)
		{
			particles[i].pos.x = ofRandom(0, ofGetWidth());
			particles[i].pos.y = ofRandom(0, ofGetHeight());
			particles[i].vel = ofVec3f();
		}
		
		// clear background
		ofBackground(255);
	}
	else if (key == 'f' || key == 'F')
	{
		// 'F' toggle field draw
		bDrawField = !bDrawField;
	}
	else if (key == 't' || key == 'T')
	{
		// 'T' toggle trails
		bDrawTrails = !bDrawTrails;
		ofSetBackgroundAuto(!bDrawTrails);
	}
	
	// adjust damping using up, down arrows

	else if (key == OF_KEY_UP)
	{
		damping += 0.01;
	}
	else if (key == OF_KEY_DOWN)
	{
		damping -= 0.01;
		if (damping < 0) damping = 0;
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
