#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	/* define a triangle mesh
	 
			0--1
			| /
			|/
			2
	 */
	
	ofVec3f pt0 = ofVec3f(0, 0, 0);
	ofVec3f pt1 = ofVec3f(100, 0, 0);
	ofVec3f pt2 = ofVec3f(0, -100, 0);
	
	triangle.addVertex(pt0);	// add points in clockwise direction
	triangle.addVertex(pt1);
	triangle.addVertex(pt2);
	
	triangle.addColor(ofColor::red);
	triangle.addColor(ofColor::green);
	triangle.addColor(ofColor::blue);
	
	// add 3 vertex indices in a row
	// to make a triangle between them:
	
	triangle.addIndex(0);
	triangle.addIndex(1);
	triangle.addIndex(2);
	
	// we'll add texture coordinates to manually map
	// an image to the triangle
	
	image.load("image.jpg");
	
	triangle.addTexCoord(ofVec2f(0,0));
	triangle.addTexCoord(ofVec2f(image.getWidth(),0));
	triangle.addTexCoord(ofVec2f(0,image.getHeight()));
	
	
	
	// sphere
	
	sphere = ofSpherePrimitive(250, 100);	// radius, resolution
	sphere.setPosition(-500, 0, 0);
	
	// box / cube
	
	box = ofBoxPrimitive(200, 100, 300);	// width, height, depth
	box.setPosition(400, 0, 0);
	
	
	// setup lights
	
	ofSetSmoothLighting(true);		// nicer lighting rendering

	
	// setup point light
	
	light.setPointLight();
	
	light.setPosition(0, 0, 200);
	light.setDiffuseColor( ofColor::white );

	light.setAttenuation(.5);	// adjust the light throw
	
	
	// setup spot light
	
	spotlight.setSpotlight();
	
	spotlight.setPosition(300, 0, 0);
	spotlight.lookAt(sphere);
	spotlight.setDiffuseColor( ofColor::blue );
	light.setSpecularColor( ofColor::fuchsia );

	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	float time = ofGetElapsedTimef();

	
	// animate the point light to oscillate in Z direction
	
	ofVec3f pointPos = light.getPosition();
	pointPos.z = sin( time ) * 300.;
	light.setPosition( pointPos );
	
	
	// animate spotlight to orbit around sphere
	
	ofVec3f spotPos = sphere.getPosition();
	spotPos.x += cos( time ) * sphere.getRadius() * 1.5;
	spotPos.y += sin( time ) * sphere.getRadius() * 1.5;
	spotPos.z += sin( time * 2. ) * sphere.getRadius() * 1.5;
	
	spotlight.setPosition(spotPos);
	
	spotlight.lookAt(sphere);	// point at sphere center
	
	
	// rotate our box 1 degree in a noisy direction
	
	box.rotate(1, ofNoise(time), ofNoise(time+1000), ofNoise(time+2000));

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();		// begin viewing our scene from the camera
	
	ofEnableLighting();		// turn on lighting globally
	ofEnableDepthTest();	// render objects in order of depth
	
	light.enable();			// enable our lights
	spotlight.enable();
	
	
	image.bind();					// map image to triangle mesh
	triangle.disableColors();		// turn off mesh color tint
	triangle.draw();
	image.unbind();
	
	sphere.draw();
	box.draw();
	
	light.disable();			// disable our scene lights
	spotlight.disable();
	
	ofDisableLighting();		// disable global lighting
	
	
	ofDrawAxis(100);			// draws our scene origin axes

	spotlight.draw();			// visualize our lights
	light.draw();
	
	// visualize the 3d wireframes
	ofSetColor(255, 100);		// add some alpha
	sphere.drawWireframe();		// visualize the sphere mesh
	box.drawWireframe();
	ofSetColor(255);
	
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
