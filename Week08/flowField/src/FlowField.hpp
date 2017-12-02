//
//  FlowField.hpp
//  flowField
//
//  Created by Tyler on 10/19/17.
//
//

#pragma once
#include "ofMain.h"

class FlowField {
	
public:
	
	FlowField();
	~FlowField(){}
	
	FlowField(float w, float h, float res);
	
	void initRandom(float scale);	// initialize random field
	void initNoise(float scale);	// init wavy field
	
	ofVec3f getForceAt(ofVec3f pos);
	
	void draw(float scale);
	
	// our "field" is a 2D grid of forces
	// which we store as a 1D vector:
	
	vector<ofVec3f> field;
	
	int nCols, nRows;					// grid size

	float width, height, resolution;	// pixel dimensions
	

};