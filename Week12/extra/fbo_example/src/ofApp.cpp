#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofDisableArbTex();
	
	fbo.allocate(1024, 768);
	
	plane.set(200,300,10,10, OF_PRIMITIVE_TRIANGLES);
	
	
	auto& vertices = plane.getMesh().getVertices();
	
	for (int i=0; i<vertices.size(); i++)
	{
		vertices[i].z += ofRandom(-10,10);
	}
	

	img.load("img.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofSetColor(255);
	
	fbo.begin();
	
	ofBackground(0);
	
	img.draw(0,0,1024,768);
	
	ofSetColor(ofColor::red);
	
	ofDrawCircle( ofRandom(1024), ofRandom(768), ofRandom(10,100));
	
	fbo.end();
	
	
	
	
	
	//plane.rotate(1, ofVec3f(0,1,0));
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(255);
	
//	fbo.draw(0,0);
	
	
	ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);
	
	ofEnableDepthTest();
	
	
	fbo.getTexture().bind();
	plane.draw();
	fbo.getTexture().unbind();
	
	ofDisableDepthTest();

	
	ofSetColor(0);
	plane.drawWireframe();
	
	



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
