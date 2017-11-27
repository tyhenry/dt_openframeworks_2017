#pragma once

#include "ofMain.h"
#include "Brushes.h"

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

	BrushCircle circleBrush;
	BrushSquare squareBrush;

	// we'll demonstrate "polymorphism" by using a pointer to the active brush
	// - we can point to any type that inherits from Brush
	
	Brush* activeBrush;		// pointer to the brush we're drawing with

};
