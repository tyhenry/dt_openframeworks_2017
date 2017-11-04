#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	ofSetFrameRate(30);
	
	ofDisableArbTex();	// map image textures properly to of3DPrimitive meshes
	
	// enable web cam
	
	vid.listDevices();		// just prints all your video cameras to console

	vid.setup(640, 480);	// start default cam at 640x480
	
	// setup the slitscan object
	
	slitScan = SlitScan(640, 480);  // create slit scan
	
	// setup the mesh
	
	mesh = ofMesh::plane(640, 480, 128, 96);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	vid.update();		// update web cam
	
	if (vid.isFrameNew())
	{
		// update the slit scan
		
		slitScan.addLine(vid.getTexture());
		
		
		// update the mesh z based on slit scan brightness:
		
		// grab the pixels to read color
		ofPixels pix = slitScan.getPixels();
		
		// loop through the mesh
		for (int i=0; i<mesh.getVertices().size(); i++)
		{
			
			ofVec3f vert	= mesh.getVertex(i);
			
			float imgX	= ofMap(vert.x, -320, 320, 0, pix.getWidth()-1);
			float imgY	= ofMap(vert.y, -240, 240, 0, pix.getHeight()-1);
			ofColor color	= pix.getColor(imgX, imgY);
			vert.z	= ofMap( color.getBrightness(), 0, 255, 0, 100);
			
			// update vert z
			mesh.setVertex(i, vert);
		}
	}
	
	// increment scene rotation
	
	rotation -= 0.1;

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// shifting background hue
	float sinTime = sin(ofGetElapsedTimef() * .1);
	float bgHue = ofMap( sinTime, -1, 1, 0, 255);
	ofBackground( ofColor::fromHsb(bgHue,255,255) );

	
	cam.begin();
	ofEnableDepthTest();
	
	// rotate scene
	ofRotateX(rotation);
	
	
	slitScan.bind();
	if (bDrawPoints)
		mesh.drawVertices();
	else
		mesh.draw();
	slitScan.unbind();
	
	if (bDrawWireframe)
		mesh.drawWireframe();

	
	ofDisableDepthTest();
	cam.end();
	
	// on screen text
	stringstream ss;
	ss
		<< "'W': draw wireframe [" << bDrawWireframe << "]" << endl
		<< "'P': draw point cloud [" << bDrawPoints << "]";
	ofDrawBitmapStringHighlight(ss.str(), 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 'w' || key == 'W')
	{
		bDrawWireframe = !bDrawWireframe;
	}
	else if (key == 'p' || key == 'P')
	{
		bDrawPoints = !bDrawPoints;
	}

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
