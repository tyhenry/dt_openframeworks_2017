//
//  Terrain.hpp
//  Terrain
//
//  Created by Tyler on 11/3/17.
//
//

#pragma once
#include "ofMain.h"

class Terrain {
	
public:
	
	Terrain();
	Terrain(float w, float h, float cols, float rows);
	~Terrain(){}
	
	// we'll create our terrain features
	// based on the brightness values of an image:
	
	void applyHeightMap(ofImage map, float maxHeight);
	// map: black = 0, white = maxHeight
	
	void draw();
	void drawNormals(float length = 10.);
	
	ofMesh mesh;		// the 3D landscape mesh
					// (an x-y grid, with height in +z)
	
	
private:
	
	float width, height;	// grid settings
	int nCols, nRows;
	
	void calculateNormals();
	

};