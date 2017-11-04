//
//  Terrain.cpp
//  Terrain
//
//  Created by Tyler on 11/3/17.
//
//

#include "Terrain.hpp"

Terrain::Terrain() : Terrain(1000,1000, 100, 100)	// default to alternate constructor
{}

Terrain::Terrain(float w, float h, float cols, float rows)
{
	width = w;
	height = h;
	nCols = cols;
	nRows = rows;
	
	// create an x-y grid mesh
	// with w x h area, and cols x rows grid
	
	// remember the mesh is *centered* at 0,0
	
	mesh = ofMesh::plane(width, height, nCols, nRows, OF_PRIMITIVE_TRIANGLES);
	
}

void Terrain::applyHeightMap(ofImage map, float maxHeight)
{
	
	// set z height of mesh grid from brightness values in map image:
	
	for (int i=0; i<mesh.getVertices().size(); i++)
	{
		ofVec3f vert = mesh.getVertex(i);
		
		// map mesh x-y vertex to image x-y coords
		float imgX = ofMap(vert.x, -width/2, width/2, 0, map.getWidth()-1, true);
		float imgY = ofMap(vert.y, -height/2, height/2, 0, map.getHeight()-1, true);
		
		// get the color
		ofColor col = map.getColor(imgX, imgY);
		
		// map the brightness to Z on mesh vertex
		// (Z "pulls" the vertex towards us)
		vert.z = ofMap(col.getBrightness(), 0, 255, 0, maxHeight);
		
		mesh.setVertex(i, vert);
	}
	
	// update the mesh normals to work with lighting!
	
	calculateNormals();
}

void Terrain::draw()
{
	// in our x-y mesh, "up" is +Z (our mapped height)
	// but for a 3D landscape, "up" is +Y!
	
	// we can fix this
	// by rotating around X axis when we draw:
	
	ofPushMatrix();		// keep this rotation local!
	ofRotateX(-90);		// rotate -90 degrees around X (+z -> +y)
	
	mesh.draw();
	
	ofPopMatrix();		// end the local rotation transformation
	
	// ofPopMatrix() *always* comes after ofPushMatrix()!!!
	
}

void Terrain::calculateNormals()
{
	
	// normals point out perpendicularly from the mesh
	// and give openFrameworks important information
	// about how to light the mesh
	
	// whenever we alter the mesh, we need to recalculate the normals
	
	// NOTE!!
	
	// this code is copied directly from Zach Lieberman's
	// ofxMeshUtils addon:
	// https://github.com/ofZach/ofxMeshUtils/blob/master/src/ofxMeshUtils.cpp#L32-L58
	
	
	mesh.clearNormals();
	
	// create 1 empty normal per vertex
	for( int i=0; i < mesh.getVertices().size(); i++ )
	{
		mesh.addNormal(ofPoint(0,0,0));
	}
	
	// calculate the normals
	// based on mesh triangle orientations
	for( int i=0; i < mesh.getIndices().size(); i+=3 )
	{
		// triangle indices
		const int ia = mesh.getIndices()[i];
		const int ib = mesh.getIndices()[i+1];
		const int ic = mesh.getIndices()[i+2];
		
		// calculate normal using cross product of vectors
		ofVec3f e1 = mesh.getVertices()[ia] - mesh.getVertices()[ib];
		ofVec3f e2 = mesh.getVertices()[ic] - mesh.getVertices()[ib];
		ofVec3f normal = e2.cross( e1 );
		normal.normalize();
		
		// depending on your clockwise / winding order, you might want to reverse the e2 / e1 above if your normals are flipped.
		
		mesh.getNormals()[ia] = normal;
		mesh.getNormals()[ib] = normal;
		mesh.getNormals()[ic] = normal;
		
	}
	
}

void Terrain::drawNormals(float length)
// only call this function if you have a small number of polygons, otherwise it will
// make your scene run real slow!
{
	if (mesh.getVertices().size() != mesh.getNormals().size())
		return; // abort
	
	ofPushMatrix();		// keep this rotation local!
	ofRotateX(-90);		// rotate -90 degrees around X (+z -> +y)
	for (int i=0; i<mesh.getNormals().size(); i+=3)	// every 3 normals are the same
	{
		ofVec3f normal = mesh.getNormals()[i];
		ofVec3f point = mesh.getVertices()[i];
		ofDrawLine(point, point + normal * length);
	}
	ofPopMatrix();
	
}

		
		
