#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	for (int y=0; y< ofGetHeight(); y+=20){
		for (int x=0; x< ofGetWidth(); x+=20){
			
			Mover mover;
			mover.pos = ofVec2f(x,y);
			movers.push_back(mover);
			
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofVec3f mousePos = ofVec3f(ofGetMouseX(), ofGetMouseY());
	
	for (int i=0; i<movers.size(); i++){
	
		ofVec3f attraction, repulsion;
		
		ofVec3f dir = mousePos - movers[i].pos;
		
		float dist = dir.length();
		
		if (dist < 100) {
			repulsion = dir.getNormalized() * -1.;
		} else if ( dist < 200){
			attraction = dir.getNormalized();
		}
		
		movers[i].applyForce(attraction);
		movers[i].applyForce(repulsion);
		movers[i].applyDampingForce(0.05);
		movers[i].update();
		
		movers[i].checkEdges();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (int i=0; i<movers.size(); i++){
		movers[i].draw();
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
