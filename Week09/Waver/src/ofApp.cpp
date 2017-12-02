#include "ofApp.h"
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	
	// load image
	
	img.load("cat.jpg");
	img.resize( 1024, 1024);
	
	
	/* 
	 build a grid mesh to display our image:
	 
		 0---1---2
		 |   |   |
		 1---*---*
		 |   |   |
		 2---*---*
	 
	*/
	
	// you can do something quick like this!
	// mesh = ofMesh::plane( 1024, 1024, 50, 50 );		// builds a 1024x1024 plane, with 50x50 grid divisions
	
	
	
	// we'll make a grid by hand to see how it's done:
	/*-----------------------------------------------*/
	
	
	ofVec2f size		= ofVec2f( 1024, 1024 );	// mesh size
	
	int cols			= 50;						// # grid lines
	int rows			= 50;
	
	float xGap		= size.x / (cols-1);		// size of grid gaps
	float yGap		= size.y / (rows-1);
	
	
	// add mesh vertices and texture coordinates at grid points
	
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			
			
			// vertex			- the mesh point in 3D space
			/*-----------------------------------------------*/
			
			ofVec3f vertex		= ofVec2f( x * xGap, y * yGap );	// x,y grid (z is 0)
			
			mesh.addVertex( vertex - (size * .5));					// offset vert to center mesh at 0,0

			
			// texture coord	- 2D image coordinates
			/*-----------------------------------------------*/
			
			// map the vertex to a point on the image
			
			ofVec2f texCoord;
			texCoord.x			= ofMap(vertex.x, 0, size.x, 0, img.getWidth());
			texCoord.y			= ofMap(vertex.y, 0, size.y, img.getHeight(), 0);	// invert y to flip image
			
			mesh.addTexCoord( texCoord );
			
			// add default white color
			mesh.addColor(ofColor::white);
			
			
			// triangle indices	 - connect the mesh vertices as triangles
			/*-------------------------------------------------------------*/
			
			if (x < cols - 1 && y < rows - 1)	// skip the final column and row
			{
			
				// 1 grid square = 2 triangles
				/*
					grid index:	 A-------B
								 |     / |
								 |   /   |
								 | /     |
								 D-------C
				 */
				
				int index	= x + y * cols;			// A, this index in mesh vertices vector
					
				// triangle 1
				mesh.addIndex (index);				// A
				mesh.addIndex (index + 1);			// B, next grid index
				mesh.addIndex (index + cols);		// D, next grid row
				
				// triangle 2
				mesh.addIndex (index + 1);			// B
				mesh.addIndex (index + 1 + cols);	// C
				mesh.addIndex (index + cols);		// D
			}
		}
	}
	
	
	// set up the lighting
	
	ofSetSmoothLighting(true);
	light.setPosition( 0,0,0 );				// set as origin
	light.setPointLight();					// point light shines in all directions
	light.setDiffuseColor( ofColor(255) );	// white light
	
//	light.setAttenuation( 0.5,0,0 );	// brightens the light

	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	// add some noise to the mesh vertices
	
	float time = ofGetElapsedTimef();
	
	for (int i=0; i < mesh.getVertices().size(); i++)
	{
		ofVec3f vert	= mesh.getVertex(i);
		float noise		= ofSignedNoise( vert.x * .001, vert.y * .001, time );
		vert.z			= noise * 50.;
		mesh.setVertex(i, vert);
	}
	
	
	// move the pan cam
	
	float radius		= 512;
	
	ofVec3f center = ofVec3f (0,0,0);
	float x = cos(ofGetElapsedTimef()*0.5) * radius;
	float y = sin(ofGetElapsedTimef()*0.5) * radius;
	
	panCam.setPosition(x,y,200);
	panCam.lookAt(center, ofVec3f(0,0,1)); // ofVec3f argument denotes sky (z axis)
	
	
	// match light to the pan cam, but smaller orbit
	
	light.setPosition( panCam.getPosition() * .5 );
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableDepthTest();		// turn on depth-based render order
	ofEnableLighting();			// turn on lighting calculations
	
	// start the camera view
	
	if (bUsePanCam)
		panCam.begin();		// orbit camera
	else
		easyCam.begin();	// mouse controlled camera
	
	
	light.enable();			// enable our light
	
	// draw the mesh with image
	
	img.bind();
	mesh.draw();
	img.unbind();
	
	
	// draw the cameras and light for reference
	panCam.draw();
	easyCam.draw();
	light.draw();
	
	
	if (bUsePanCam)
		panCam.end();		// end camera view
	else
		easyCam.end();
	
	
	ofDisableLighting();
	ofDisableDepthTest();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key=='c'){
		bUsePanCam = !bUsePanCam;
	}
	
}
//
//
//
////--------------------------------------------------------------
//void ofApp::setup()
//{
//	
//	ofBackground(0);
//	
//	// let's build a grid
//	
//	const float width	= 500.;		// size
//	const float height	= 500.;
//	
//	const float cols	= 10.;		// grid lines
//	const float rows	= 10.;
//	
//	
//	// grid resolution
//	float xRes			= width / cols;		// gap size between 2 vertices
//	float yRes			= height / rows;
//	
//	int numVerts			= cols * rows;
//	ofVec2f size			= ofVec2f( width, height );
//	
//	
//	// add points to grid
//	
//	for (int y = 0; y <= rows; y++) {
//		for (int x = 0; x <= cols; x++) {
//			
//			ofVec3f vert		= ofVec2f(x * xRes, y * yRes);		// vertex position
//			ofVec2f texCoord	= vert / size;					// tex coord: pct of image, 0.-1.
//			
//			mesh.addVertex( vert - (size * .5) );				// offset vertex so center is at 0,0
//			mesh.addTexCoord( texCoord );
//		}
//	}
//	
//	// connect mesh indices into triangles
//	
//	for (int y = 0; y < rows; y++) {
//		for (int x = 0; x < cols; x++) {
//			
//			int index = x + y * cols;
//			
//			// triangles:
//			/*
//				index:	A-------B
//						|     / |
//						|   /   |
//						| /     |
//						D-------C
//			 */
//			
//			
//			int a = index;				// a == this index
//			int b = index + 1;			// b == next index
//
//			int c = b + cols;			// c == next index, next row
//			int d = a + cols;			// d == this index, next row
//			
//			// tri 1
//			mesh.addIndex( a );		//  a__b
//			mesh.addIndex( b );		//	| /
//			mesh.addIndex( d );		//  |/
//									//  d
//			
//			// tri 2
//			mesh.addIndex( b );		//     b
//			mesh.addIndex( c );		//    /|
//			mesh.addIndex( d );		//   / |
//									//  d--c
//			
//		}
//	}
//	
//	// So, you could do above, or just write:
//	
//	// mesh = ofMesh::plane(width, height, cols, rows);  // which does it for you :)
//	
//	
//	// load the image
//	
//	ofEnableNormalizedTexCoords();
//	img.load("sat.jpg");
//	img.resize(size.x, size.y);		// set size to match mesh
//	
//
//}
//
////--------------------------------------------------------------
//void ofApp::update(){
//	
//	// update the pan cam orbit pos
//	
//	float time = ofGetElapsedTimef();
//	
//	ofVec3f camPos;
//	camPos.x = cos(time * .2) * 500.;		// circle around x and z axes
//	camPos.z = sin(time * .2) * 500.;
//	
//	panCam.setPosition(camPos);
//	panCam.lookAt(ofVec3f());
//	
//	
//	// update the mesh vertices
//	
//	for (int i=0; i<=mesh.getVertices().size(); i++)
//	{
//		ofVec3f& vert = mesh.getVertices()[i];		// use '&' to reference the vertex, rather than copy
//		
//		vert.z = ofSignedNoise( vert.x, vert.y, time * .5) * 10.;
//	}
//
//}
//
////--------------------------------------------------------------
//void ofApp::draw(){
//	
//	
//	ofEnableDepthTest();
//	
//	panCam.begin();
//	
//	img.bind();
//	mesh.draw();
//	img.unbind();
//	
//	ofDrawAxis(100);
//	
//	panCam.end();
//	
//	ofDisableDepthTest();
//
//}
//
////--------------------------------------------------------------
//void ofApp::keyPressed(int key){
//
//}

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
