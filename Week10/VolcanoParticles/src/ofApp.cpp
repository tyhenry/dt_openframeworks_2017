#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(70, 20, 20);
	
	ofSetSmoothLighting(true);
	
	ofSetFrameRate(60);
	
	
	// setup the cone radius, height, and resolution x and y
	volcano.set(350, 500, 100, 100);
	
	
	// volcano is an ofConePrimitive
	
	// all of3dPrimitives contain an ofMesh
	// but also allow for translation, rotation, and scale
	
	// rotate 180 around x axis to point up
	volcano.rotate(180, ofVec3f(1,0,0));
	
	
	// let's move the cone's peak into the volcano...
	
	vector<ofVec3f>& coneVerts = volcano.getMesh().getVertices();

	for (int i=0; i<coneVerts.size(); i++)
	{
		if (coneVerts[i].y <= -90)
		{
			coneVerts[i].y += 250;
		}
		
		// add some mesh noise for an organic mountain
		ofVec3f nPos = coneVerts[i] * 0.02;
		coneVerts[i].x += ofSignedNoise( nPos.x ) * 20.;
		coneVerts[i].y += ofSignedNoise( nPos.y ) * 20.;
		coneVerts[i].z += ofSignedNoise( nPos.z ) * 20.;
	}
	
	
	// create the ground
	
	ground.set(10000, 10000, 1000, 1000);
	ground.rotate(-90, ofVec3f(1,0,0));
	ground.move(0, -250, 0);
	
	
	// gravity
	gravity = ofVec3f(0,-.002,0);
	
	
	// lights
	firelight.setPointLight();
	firelight.setPosition(0,250,0);
	firelight.setDiffuseColor( ofColor::red );
//	firelight.setAttenuation(0.1, .5, 1);

	
	sunlight.setDirectional();
	sunlight.setPosition(100,50,-5);
	sunlight.setDiffuseColor( ofColor::wheat);
	sunlight.lookAt(ofVec3f(0));
	sunlight.rotate(180, 0,1,0);
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// spawn new eruption particles
	for (int i=0; i<10; i++)
	{
		Particle p;
		p.vel.x = ofRandom(-1,1);
		p.vel.y = ofRandom(1.5,4);	// up
		p.vel.z = ofRandom(-1,1);
		p.lifespan = ofRandom(7,9);
		p.mass = ofRandom(.7,1.3);
		eruption.push_back(p);
	}
	
	while (eruption.size() > 5000)
	{
		eruption.erase(eruption.begin());
	}
	
	for (int i=0; i<eruption.size(); i++)
	{
		eruption[i].applyForce(gravity);
		eruption[i].update();
	}
	

	// use noise to animate the fire brightness
	float brt = ofNoise(ofGetElapsedTimef() * 2.) * 255.;
	firelight.setDiffuseColor( ofColor::fromHsb(10, 255, brt));

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableLighting();
	
	cam.begin();
	ofEnableDepthTest();
	
	firelight.enable();
	
	for (int i=0; i<eruption.size(); i++)
	{
		eruption[i].draw();
	}
	
	sunlight.enable();
	
	ofSetColor( ofColor(73, 48, 35) );
	volcano.draw();
	volcano.drawAxes(100);
	
	ofSetColor( ofColor(70,120,10));
	ground.draw();
	ofSetColor(255);
	
	firelight.disable();
	sunlight.disable();
	ofDisableLighting();
	
	ofDisableDepthTest();
	
	// you can draw the lights on top of your scene
//	 firelight.draw();
//	 sunlight.draw();
	
	
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
