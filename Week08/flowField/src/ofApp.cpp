#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	// create the flow field at window size, with 20 px grid gaps
	flowField = FlowField(ofGetWidth(), ofGetHeight(), 20.);
	
	// add noise to the field, with .1 magnitude forces
	flowField.initNoise(0.1);
	
	// make a bunch of particles
	for (int i=0; i<5000; i++){
		
		Particle p;
		p.pos.x = ofRandom(0, ofGetWidth());
		p.pos.y = ofRandom(0, ofGetHeight());
		
		particles.push_back(p);
	}
	
	// draw particle trails - 't' on keyboard

	bDrawTrails = false;
	
	// draw the flow field - 'f' on keyboard
	
	bDrawField = false;
	
	// animate the flow field noise - 'a' on keyboard
	
	bAnimateField = true;
	
	// adjust damping using up/down arrows:
	// damping slows particles
	damping = 0.05;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (bAnimateField)
	{
		// if we're animating the field, update noise
		flowField.initNoise(0.1);
	}
	
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
	
	if (bDrawTrails)
	{
		// draw a semi-transparent black background
		// to create fading particle trails
		ofPushStyle();
		ofSetColor(0, 20);
		ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
		ofPopStyle();
	}
	
	if (bDrawField)
	{
		// draw forces x100 magnitude to see them
		flowField.draw(100.);
	}
	
	for (int i=0; i<particles.size(); i++)
	{
		particles[i].draw();
	}
	
	
	// draw the text labels
	
	string label =	"press 'T' : draw particles trails \n";
	label +=			"press 'F' : draw flow field \n";
	label +=			"press 'A' : animate field \n";
	label +=			"press ' ' : reset particle positions \n";
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
	else if (key == 'a' || key == 'A')
	{
		// 'A' toggle field animation
		bAnimateField = !bAnimateField;
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
