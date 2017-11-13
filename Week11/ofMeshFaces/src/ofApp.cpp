#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	sphere = ofIcoSpherePrimitive(200, 3);
	
	origTriangles = sphere.getMesh().getUniqueFaces();

}

//--------------------------------------------------------------
void ofApp::update(){
	
	//sine for offsetting faces
	float offset = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 500);
	
	//undulating faces
	triangles = sphere.getMesh().getUniqueFaces();
	
	for(int i = 0; i < triangles.size(); i++ ) {
		
		ofVec3f faceNormal = triangles[i].getFaceNormal();
		
		float hue		= ofMap(i, 0, triangles.size(), 0, 255);
		ofColor color	= ofColor::fromHsb(hue, 255, 255);
		
		for(int j = 0; j < 3; j++ ) {
			triangles[i].setVertex(j, origTriangles[i].getVertex(j) - faceNormal*offset);
			triangles[i].setColor(j, color);
		}
	}
	
	sphere.getMesh().setFromTriangles( triangles );

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();
	ofEnableDepthTest();
	
	ofDrawAxis(100);
	
	sphere.draw();
	
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
