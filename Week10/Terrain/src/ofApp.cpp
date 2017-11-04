#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	
	// setup our scene
	
	ofBackground(0);
	
	ofSetVerticalSync(true);	// syncs framerate to monitor refresh rate
	
	ofSetSmoothLighting(true);		// nicer lighting
	
	ofDisableArbTex();				// we call this to make our image textures map properly to meshes
	
	
	// generate a terrain of size 1000 x 1000, and grid size 1000 x 1000
	
	terrain = Terrain(1000,1000, 1000,1000);
	
	// use an image to "height-map" our terrain features:
	
	heightMap.load("crater.png");
	terrain.applyHeightMap(heightMap, 100);	// 100 = max height of terrain
	
	
	// load an image to texture the terrain:
	
	textureMap.load("crater_texture.jpg");

	
	
	// setup the sunlight
	
	
	// Directional Lights emit light based on their orientation, regardless of their position
	sunlight.setDiffuseColor(ofColor(255.f));
	sunlight.setSpecularColor(ofColor(255.f));
	sunlight.setDirectional();
	
	
	// create a moon
	
	moon = ofSpherePrimitive(10, 100);
	moon.setPosition(500, 400, -700);
	
	
	// create some stars for night mode!
	
	ofMesh sphere = ofMesh::sphere(2000, 250);	// make a big sphere mesh for our night sky
	
	// randomly add stars based on sphere vertices
	
	for (int i=0; i<sphere.getVertices().size(); i++)
	{
		if (ofRandom(0,25) < 1)		// 1 out of 25 chance to be a star
		{
			starfield.addVertex( sphere.getVertices()[i] );
		}
	}
	
	
	bDrawHeightMap = false;
	bDrawAxis = false;
	bDrawNormals = false;
	
	
	// setup the camera position
	
	cam.setAutoDistance(false);		// manually adjust ofEasyCam
	cam.setDistance(400);			// set default distance to target

	cam.setPosition(-450, 150, 350);	// set the initial position of the camera
	cam.setTarget(ofVec3f(0,0,0));	// set ofEasyCam to look at center of scene


}

//--------------------------------------------------------------
void ofApp::update(){
	
	// sun will slowly orbit an arc over the landscape
	
	float time = ofGetElapsedTimef();
	
	
	// x axis is east/west, y is up/down
	
	ofVec3f sun;
	
	sun.x = cos(time * -.2) * 500;	// counter-clockwise
	sun.y = sin(time * .2) * 500;
	
	sunlight.setPosition(sun.x, sun.y, 0);
	
	sunlight.lookAt(ofVec3f(0));	// point light towards center of scene
	sunlight.pan(180);				// lookAt points away, so this is a hack to fix
	
	
	// set the sunlight color based on sun height
	// to simulate sunrise/sunset
	
	ofColor color;
	color.r = 255;
	color.g = ofMap( sun.y, 0, 500, 100, 255, true);
	color.b = ofMap( sun.y, 0, 500, 150, 255, true);
	sunlight.setDiffuseColor( color );
	
	// set the sky color
	
	ofColor sky;
	sky.r = ofMap( sun.y, -200, 250, 0, 122, true);
	sky.g = ofMap( sun.y, 0, 500, 0, 200, true);
	sky.b = ofMap( sun.y, -100, 250, 0, 255, true);
	
	ofBackground(sky);
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	cam.begin();
	
	ofEnableDepthTest();	// draw using depth order
	ofEnableLighting();		// turn on lighting
	
	
	// draw the landscape
	
	
	sunlight.enable();		// turn on the sun light
	
	
	if (bDrawHeightMap)
		heightMap.bind();		// use height map as texture
	else
		textureMap.bind();		// or the painted texture

	
	terrain.draw();				// draw the mesh with texture

	
	if (bDrawHeightMap)
		heightMap.unbind();		// turn off the texture
	else
		textureMap.unbind();
	
	
	// draw moon with sunlighting
	
	moon.draw();
	
	
	sunlight.disable();		// turn off the sun
	
	ofDisableLighting();	// disable global lighting
	
	
	
	// draw the "sun"
	
	ofPushStyle();
	ofSetColor( sunlight.getDiffuseColor() );		// tint the sun in the diffuse color
	sunlight.draw();
	ofPopStyle();
	

	
	// draw stars
	
	ofPushStyle();
	float starAlpha = ofMap( sunlight.getPosition().y, -200, 200, 255, 50, true);
	ofSetColor(ofColor(255, starAlpha));
	starfield.drawVertices();	// draw the star "mesh" as just points
	ofPopStyle();
	
	
	
	// draw terrain normals? (warning: can slow render!)
	
	if (bDrawNormals)
		terrain.drawNormals(5);
	
	
	ofDisableDepthTest();	// draw using regular draw order
	
	
	// draw scene axis?
	
	if (bDrawAxis)
		ofDrawAxis(100);	// draw on top
	
	
	cam.end();				// end camera view
	
	
	// print settings on screen:
	stringstream ss;
	ss
	<< "'H': draw the height map [" << bDrawHeightMap << "]" << endl
	<< "'A': draw the origin axis [" << bDrawAxis << "]" << endl
	<< "'N': draw the normals (slow!) [" << bDrawNormals<< "]";
	
	ofDrawBitmapStringHighlight(ss.str(), ofVec2f(20,20));
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	if (key == 'h' || key == 'H')	// draw height map on terrain
	{
		bDrawHeightMap = !bDrawHeightMap;
	}
	if (key == 'a' || key == 'A')
	{
		bDrawAxis = !bDrawAxis;
	}
	if (key == 'n' || key == 'N')
	{
		bDrawNormals = !bDrawNormals;
	}

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
