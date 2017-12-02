#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	ofSetFrameRate(60.);

	sphere.setRadius(250);
	sphere.setResolution(4);

	// ofSpherePrimitive is a child class of of3dPrimitive
	// of3dPrimitives contain a mesh, which is the foundation of controlling and drawing 3D shapes

	// let's print the sphere's mesh contents to the console

	ofMesh& mesh = sphere.getMesh();	// get a reference to the sphere's mesh

	// a mesh contains a bunch of vectors:
	// - vertices:	vector<ofVec3f>		- vertices are the points of our mesh in space
	// - indices:	vector<int>			- indices mark which vertices are connected as triangles, every 3 indices makes 1 triangle
	// - tex coords: vector<ofVec2f>	- texture coordinates mark how the vertices of the mesh correspond to 2D images

	ofLog()
		<< "sphere mesh contains: " << endl
		<< "\t- " << mesh.getNumVertices() << " vertices" << endl
		<< "\t- " << mesh.getIndices().size() << " indices" << endl
		<< "\t- " <<  mesh.getTexCoords().size() << " texture coordinates" << endl;

	ofDisableArbTex();
	video.setup(640,480);

	sphere.rotate(180, ofVec3f(0,1,0));

	bDrawWireframe = true;
}

//--------------------------------------------------------------
void ofApp::update(){

	float time = ofGetElapsedTimef();

	// mouse x controls noise multiplier
	float noiseMult = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0., 50.);

	// mouse y controls noise frequency
	float noiseFreq = ofMap(ofGetMouseY(), 0, ofGetHeight(), .1, 5.);

	ofMesh& mesh = sphere.getMesh();	// "&" marks the variable as a reference
	// a reference is like a link or a nickname
	// here, we are directly referencing the sphere's mesh, not making a copy

	for (int v = 0; v < mesh.getNumVertices(); v++)
	{
		ofVec3f& vertex = mesh.getVertices()[v];	// reference to current vertex
		vertex.normalize();

		float noise = ofSignedNoise(vertex * noiseFreq + ofVec3f(time * .1));
		vertex *= 250 + noise * noiseMult;

	}

	ofVec3f rot;
	rot.x = sin(time * .1);
	rot.y = 1.; //sin(time * .1 +500);
	rot.z = sin(time * .1 +1000);
	sphere.rotate(.1, rot);

	// update video camera
	video.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5); 

	ofEnableDepthTest();

	ofSetColor(255);

	video.bind();
	sphere.draw();
	video.unbind();

	if (bDrawWireframe)
	{
		ofSetColor(0, 100, 255);
		sphere.drawWireframe();

		ofSetColor(255, 0, 0);
		sphere.drawVertices();

		sphere.drawNormals(10);

		sphere.drawAxes(sphere.getRadius() + 100);
	}

	ofDisableDepthTest();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == ' ')
	{
		bDrawWireframe = false;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	bDrawWireframe = true;
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
