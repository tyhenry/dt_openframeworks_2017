#pragma once

#include "ofMain.h"
#include "Terrain.hpp"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	
	// our scene camera
	ofEasyCam cam;

	// our landscape
	Terrain terrain;
	
	ofImage heightMap;			// height map of the land
	ofImage textureMap;			// texture map of the land
	
	
	ofLight sunlight;			// our lighting
	
	// extras:
	
	ofMesh starfield;			// star sphere
	
	ofSpherePrimitive moon;		// our moon
	
	bool bDrawHeightMap;		// draw the height map?
	bool bDrawAxis;				// draw the origin axes?
	bool bDrawNormals;			// draw the terrain normals?

		
};
