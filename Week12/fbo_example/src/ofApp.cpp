#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofDisableArbTex();						// use normalized texture coordinates when using meshes
	
	fbo.allocate(500, 500, GL_RGB);		// allocate the fbo before using it!
	
	plane.set(400,600, 10,10, OF_PRIMITIVE_TRIANGLES);		// you can also try OF_PRIMITIVE_TRIANGLE_STRIP for a different mesh layout
	
	
	auto& vertices = plane.getMesh().getVertices();		// nickname for the mesh vertices
	
	for (int i=0; i<vertices.size(); i++)		
	{
		vertices[i].z += ofRandom(-20,20);		// randomly adjust the vertices' z 
	}
	

	img.load("img.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofSetColor(255);

	
	// anything between fbo.begin() and fbo.end() will be drawn inside the FBO, not on screen

	fbo.begin();
	
	ofClear(255,0,255);	// clear all FBO pixels to purple

	
	img.draw(0, 0, 250, 250);	// draw the image in the top left quarter of the fbo
	
	ofSetColor(ofColor::red);
	
	ofDrawCircle( ofRandom(500), ofRandom(500), ofRandom(10,50));	// random circles
	
	fbo.end();
	
	
	
	
	plane.rotate(.5f, ofVec3f(0,1,0));	// rotate the mesh .5 degree each update() around Y axis
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){

	
	ofSetColor(255);
	
	fbo.draw(0,0,250,250);	// draw the fbo smaller
	
	
	ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);
	
	ofEnableDepthTest();
	
	
	fbo.getTexture().bind();		// use the fbo to texture the mesh
	plane.draw();
	fbo.getTexture().unbind();
	
	ofDisableDepthTest();

	
	ofSetColor(ofColor::green);
	plane.drawWireframe();			// draw the mesh wireframe on top
	
	



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
