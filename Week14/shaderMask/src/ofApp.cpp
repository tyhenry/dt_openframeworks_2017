#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofDisableArbTex();
	/* ^^ this is SOMETIMES necessary when working with shaders...

	 Look at your fragment shader file (shader.frag)...
	 
	 -
	 
	 if you see "Sampler2D", like -		uniform Sampler2D tex0;
	 
	 then the shader uses NORMALIZED texture coords, and you SHOULD call ofDisableArbTex();
	 
		normalized texture coords range: (0.0, 0.0) - (1.0, 1.0)
	 
	 -
	 
	 if you see "Sampler2DRect" like - 	uniform Sampler2DRect tex0;
	 
	 then the shader uses ARBITRARY texture coords - (so DON'T call ofDisableArbTex())
	 
		arbitrary texture coords range: (0.0, 0.0) - (pixel resolution)
	
	*/
	
	ofBackground(0);
	
	
	// load the shaders from the files in bin/data:
	
	shaderMask.load("shaders/mask");		// bin/data/shaders/ mask.frag + mask.vert
	
	// note: check your console log for errors when loading shaders
	
	
	webcam.setup(640,480);				// base image

	imgMask.load("imgMask.jpg");		// mask layer
	
	
	
	
	// setup a plane for 3D drawing:
	
	plane.set(480, 360, 4,4);
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	webcam.update();
	
	plane.rotate(-0.5, ofVec3f(0,1,0));	// 0.5 deg around Y axis

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor::gold, ofColor::indigo);
	
	// draw the source material for reference
	
	webcam.draw(0,0, 320,240);
	imgMask.draw(320,0, 320,240);
	
	
	// draw masked image in 2D:
	
	shaderMask.begin();
	shaderMask.setUniformTexture("imgMask", imgMask.getTexture(), 1);
	
	webcam.draw(640,0, 320,240);
	// with draw(), the webcam's texture is automatically bound
	// to the shader as texture "tex0"
	
	shaderMask.end();
	
	
	
	// draw in 3D! :
	
	// this just contains the drawing space of the camera to bottom portion of window:
	ofRectangle viewport = ofRectangle( 0,240, ofGetWidth(),ofGetHeight()-240 ); // x,y,w,h
	easyCam.begin(viewport);
	
	easyCam.setVFlip(true);	// flips cam Y
	
	ofSetColor(ofColor::gold);
	plane.drawWireframe();		// draw plane wireframe for reference
	
	ofSetColor(255);
	
	shaderMask.begin();
	
	// manually bind the webcam texture as "tex0" :
	shaderMask.setUniformTexture("tex0", webcam.getTexture(), 0);
	shaderMask.setUniformTexture("imgMask", imgMask.getTexture(), 1);
	
	plane.draw();		// draw shader to a plane
	
	shaderMask.end();
	
	easyCam.end();


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
