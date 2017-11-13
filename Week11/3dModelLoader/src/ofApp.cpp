#include "ofApp.h"

/* model found on Sketchfab.com
 
	Pigeon 3
	https://sketchfab.com/models/4383b3f88d9646c7b2f336266eaad947
	by tomkranis 
	https://sketchfab.com/tomkranis
	licensed under CC Attribution
	http://creativecommons.org/licenses/by/4.0/)
 
 */


//--------------------------------------------------------------
void ofApp::setup(){
	
	ofDisableArbTex();

	
	model.loadModel("pigeon/pigeon3.obj");
	
	// a model can contains a bunch of meshes,
	// so we need to store each one.
	
	// copying the meshes allows us to edit them in update()
	
	for (int i=0; i<model.getMeshCount(); i++)
	{
		origMeshes.push_back(model.getMesh(i));
		materials.push_back(model.getMaterialForMesh(i));
		textures.push_back(model.getTextureForMesh(i));
	}
	
	meshes = origMeshes;	// we'll edit these
	
	bDrawWires = false;
	
	ofSetSmoothLighting(true);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	float noiseAmp = 0.1;
	
	float time = ofGetElapsedTimef();
	
	ofVec3f center = model.getSceneCenter();
	
	for (int i=0; i<meshes.size(); i++)
	{
		// add x, y noise to vertices
		
		vector<ofVec3f>& vertices = meshes[i].getVertices();
		
		for (int j=0; j<vertices.size(); j++)
		{
			
			ofVec3f origVt = origMeshes[i].getVertices()[j];
			
			origVt.x += ofSignedNoise(origVt.z * .2, time * 0.1);
			origVt.y += ofSignedNoise(origVt.z * .2, time * 0.2);
			origVt.z += ofSignedNoise(origVt.z * .2, time * 0.5);
			
			vertices[j] = origVt;
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor::darkSalmon, ofColor::indigo);
	
	cam.begin();
	ofEnableDepthTest();
	
	ofTranslate(0,-200,0);
	
	if (bDrawWires)
		ofDrawAxis(600);
	
	float scale = model.getNormalizedScale();	// this draws model at visible scale
	ofScale(scale,scale,scale);
	
	for (int i=0; i<meshes.size(); i++)
	{
		
		textures[i].bind();
		
		meshes[i].draw();
		
		textures[i].unbind();
		
		if (bDrawWires)
			meshes[i].drawWireframe();
		
	}

	
	ofDisableDepthTest();
	cam.end();
	
	// draw label
	
	ofDrawBitmapStringHighlight("hold any key to draw wireframe", 20, 20, ofColor::indigo);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	bDrawWires = true;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	bDrawWires = false;
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
