#pragma once

#include "ofMain.h"

class Brush
{
public:
	Brush(){}
	~Brush(){}
	
	virtual void draw(float x, float y) {}
};

class BrushCircle : public Brush
{
public:
	BrushCircle(){}
	
	void draw(float x, float y)
	{
		ofDrawCircle(x,y,radius);
	}
	
	int radius = 10;
	
};

class BrushRectangle : public Brush
{
public:
	BrushRectangle(){}
	
	void draw(float x, float y)
	{
		ofDrawRectangle(x,y,10,10);
	}
	
};


class Page
{
public:
	Page(){}
	~Page(){}
	
	ofImage bg;
	vector<Brush*> brushPtrs;
	Brush* currentBrush;
//	int brushIdx;
};


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
	
	vector<Page> pages;
	
	int pageNum = 0;
		
};
