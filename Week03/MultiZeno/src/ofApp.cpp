#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetCircleResolution(100);
    
    // create 10 balls
    
    int nBalls = 10;
    
    for (int i=0; i<nBalls; i++){
        
        Ball ball;
        
        ball.radius = ofMap(i, nBalls,0, 10, 50);
        // radius based on ball #, starting with biggest
        
        ball.pct    = ofMap(ball.radius, 10,50, 0.1,.03);
        // the larger the ball, the slower the interpolation speed
        

        ball.color.r = ofMap(ball.radius, 50,10, 0,255);
        ball.color.b = ofMap(ball.radius, 10,50, 0,255);
        // smaller -> red, larger -> blue
        ball.color.g = 0;
        // no green

        
        // store ball in our vector
        balls.push_back(ball);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    for (int i=0; i<balls.size(); i++){
        
        // move towards the mouse
        
        float pct = balls[i].pct; // use ball "speed" to...
        
        // interpolate ball pos:
        balls[i].pos = balls[i].pos * (1.-pct) + mouse * pct;
        
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<balls.size(); i++){
        
        ofSetColor(balls[i].color);
        ofDrawCircle(balls[i].pos, balls[i].radius);
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
