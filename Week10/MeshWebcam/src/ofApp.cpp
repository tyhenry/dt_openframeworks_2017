#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	ofSetFrameRate(30);		// match app frame rate to webcam
	
	ofDisableArbTex();	// map image textures properly to of3DPrimitive meshes

	
	mesh = ofMesh::plane(1024, 1024, 128, 128);	// 1024x1024 size, 128x128 grid
	
	// x mesh dimension: -512 to 512
	// y mesh dimension: -512 to 512
	
	
	// setup gui
	
	gui.setup();
	
	// add float slider control to gui:
	gui.add( scale.setup("scale", 1, 0, 1) );	// "label", default value, min, max
	
	// add boolean toggle controls to gui:
	
	gui.add( bNoise.setup("mesh noise", false) );	// "label", default value
	gui.add( bRotate.setup("rotate", true) );
	gui.add( bWires.setup("draw wireframe", false) );
	gui.add( bAxis.setup("draw axis", false) );
	
	
	// setup webcam
	
	vid.listDevices();	// print your webcams to the console
	
	vid.setup(640,480);	// or choose cam #0 using: vid.setup(0, 640, 480)
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	vid.update();
	
	if (vid.isFrameNew())	// only update if a new webcam frame has arrived
	{
		
		
		for (int i=0; i<mesh.getVertices().size(); i++)
		{
			ofVec3f& vertex = mesh.getVertices()[i];
			// & = direct reference to mesh vertex,
			// if we edit vertex, we edit mesh!
			
			if (bNoise)
			{
				// add z-axis noise to the mesh:

				float noise = ofSignedNoise( vertex.x * 0.01, vertex.y * 0.01, ofGetElapsedTimef() * .1);
				vertex.z = noise * 100 * scale;
			}
			else
			{
				// or add z offsets per image brightness:
				
				// map mesh coords to image coords
				float imgX = ofMap(vertex.x, -512, 512, 0, vid.getWidth()-1);
				float imgY = ofMap(vertex.y, -512, 512, 0, vid.getHeight()-1);
				
				ofColor color = vid.getPixels().getColor(imgX, imgY);
				float brightness = color.getBrightness();
				
				vertex.z = brightness * scale;
			}
			
		}
	}
	
	if (bRotate)
		rotation -= 0.2;	// decrease x rotation angle
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableDepthTest();
	
	cam.begin();
	
	ofRotateX(rotation);	// rotate the scene
	
	vid.bind();		// draw the webcam texture on the mesh
	mesh.draw();
	vid.unbind();
	
	if (bWires)
		mesh.drawWireframe();
	
	ofDisableDepthTest();
	
	if (bAxis)
		ofDrawAxis(100);		// draw the axis on top
	
	cam.end();
	

	gui.draw();
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
