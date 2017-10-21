//
//  FlowField.cpp
//  flowField
//
//  Created by Tyler on 10/19/17.
//
//

#include "FlowField.hpp"

FlowField::FlowField() {
	
}

//
//	w:		width of flow field in pixels
//	h:		height of flow field in pixels
//  res:		"resolution" of field, i.e. grid size
//
FlowField::FlowField(float w, float h, float res) {
	
	width = w;
	height = h;
	resolution = res;
	
	// calc grid:
	
	// grid size = pixel dimensions / resolution
	// (+ 1 to extend to edges)
	
	nCols = width / resolution + 1;
	nRows = height / resolution + 1;
	
	// total grid pts
	int totalPts = nCols * nRows;
	
	// fill the force vector
	for (int i=0; i<totalPts; i++)
	{
		ofVec3f flow;
		field.push_back(flow);
	}
}


// helper function to initialize random forces:

void FlowField::initRandom(float scale){
	
	for (int i=0; i<field.size(); i++)
	{
		// random x and y
		field[i].set(ofRandom(-1,1), ofRandom(-1,1));
		field[i].scale(scale);	// scale magnitude
	}
}

// helper function to initialize noise-based forces:

void FlowField::initNoise(float scale)
{
	// loop through grid
	for (int y = 0; y < nRows; y++) {
		for (int x = 0; x < nCols; x++) {
			
			//find the index in the vector container of the 2D position
			int index = (y * nCols) + x;
			
			//set a perlin noise value according to position in 2d space, and time as 3rd dimension
			ofVec3f noisePos;
			noisePos.x = x*0.1;
			noisePos.y = y*0.1;
			noisePos.z = ofGetElapsedTimef() * scale;
			float noise = ofNoise(noisePos);
			
			//map the noise value to a rotation in radians
			noise = ofMap(noise, 0, 1, 0, TWO_PI);
			
			// set the force x and y to the sin and cos of the angle
			ofVec2f force = ofVec2f(cos(noise), sin(noise));
			
			// scale magnitude
			force.scale(scale);
			
			field[index].set(force);
			
		}
	}
}

void FlowField::initFromImage(ofImage image, float scale)
{
	
	for (int y = 0; y < nRows; y++) {
		for (int x = 0; x < nCols; x++) {
			
			// finding the position of the flow in the vector container
			int index = (y * nCols) + x;
			
			// calculate flow angle based on image pixel brightness
			
			float brt	= image.getColor(x * resolution,y * resolution).getBrightness();
			
			//map the noise value to a rotation in radians
			float angle = ofMap(brt, 0, 255, 0, PI);
			
			// set the force x and y to the sin and cos of the angle
			ofVec2f force = ofVec2f(cos(angle), sin(angle));
			
			force.scale(scale);
			
			field[index].set(force);
			
		}
	}
}

ofVec3f FlowField::getForceAt(ofVec3f pos){
	
	ofVec3f force;
	force.set(0,0);
	
	// make sure the position is within the flow field
	if (pos.x < 0 || pos.x > width || pos.y < 0 || pos.y > height)
	{
		return force;
	}
	
	// map position to grid size
	int xInd = ofMap(pos.x, 0, width, 0, nCols);
	int yInd = ofMap(pos.y, 0, height, 0, nRows);
	
	// get the index of the grid position
	int index = yInd * nCols + xInd;
	
	// get the force at the index!
	force = field[index];
	return force;
}


void FlowField::draw(float scale) {
	
	// this will draw the vector grid
	// the vector magnitudes will be scaled by "scale"
	// otherwise, the forces may be too small to see!
	
	ofPushStyle();
	
	for (int y=0; y < nRows; y++){
		for (int x=0; x<nCols; x++){
			
			// get the index
			int index = y * nCols + x;

			// get the position
			ofVec3f pos = ofVec3f(x * resolution, y * resolution);
			
			// get the flow
			ofVec3f flow = field[index];
			
			// add the flow vector to the pos, with scale
			ofVec3f end = pos + field[index] * scale;
			
			// color the line based on direction
			float angle = atan2(flow.y, flow.x);
			float hue = ofMap( angle, -PI, PI, 0, 255);
			
			ofSetColor(ofColor::fromHsb(hue, 255, 200));
			
			// draw the flow line
			ofDrawLine(pos, end);
			
			// draw the origin pos as a dot
			ofDrawCircle(pos,2);
			
		}
	}
	
	ofPopStyle();
}


