#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	// easy sphere
	
	sphere = ofSpherePrimitive(1000, 50);
	// 1000 = radius, 50 = level of detail
	
	sphere.setPosition(0, 0, 0);

	
	// make a triangle mesh from 3 points
	
	ofVec3f pt0 = ofVec2f( 0, 250 );	 // center, top
	ofVec3f pt1 = ofVec2f( 289, -250);	 // right, bottom
	ofVec3f pt2 = ofVec2f( -289, -250);	 // left, bottom
	
	triangle.addVertex(pt0);
	triangle.addColor(ofColor::red);	// vertex 0 red
	
	triangle.addVertex(pt1);
	triangle.addColor(ofColor::green);	// vertex 1 green
	
	triangle.addVertex(pt2);
	triangle.addColor(ofColor::blue);	// vertex 2 blue
	
	// add 3 vertex indices in a row to connect the triangle:
	
	triangle.addIndex(0);
	triangle.addIndex(1);
	triangle.addIndex(2);
	


}

//--------------------------------------------------------------
void ofApp::update(){
	
	// rotate sphere around its y-axis:
	// sphere.rotate(ofGetElapsedTimef() * .01, ofVec3f(0,1,0));

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();
	ofEnableDepthTest();
	
	// draw background sphere, in wireframe
	
	ofSetColor(ofColor::purple);
	sphere.drawWireframe();
	
	// draw solid triangle mesh
	
	triangle.draw();
	
	
	ofDisableDepthTest();
	cam.end();
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
