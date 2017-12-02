#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetCircleResolution(100); // prettier circles
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // make a ball follow the mouse
    
    ofVec2f mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    float pct = .05; // every frame move ball 5% towards the mouse
    
    ball = ball * (1.-pct) + mouse * pct;
    
    
    // change the ball brightness with distance
    
    float dist = mouse.distance(ball);
    
    // as distance increases, brightness increases:
    brightness = ofMap(dist, 0, 500, 50, 255);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(brightness);
    ofDrawCircle(ball, 50);

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
