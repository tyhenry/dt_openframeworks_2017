#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetBackgroundAuto(false);
	

	Page page0;
//	page0.bg.load("page0_bg.jpg");
	
	page0.brushPtrs.push_back( new BrushCircle() );
	page0.brushPtrs.push_back( new BrushRectangle() );
	
	pages.push_back(page0);
	
	Page page1;
	page1.brushPtrs = page0.brushPtrs;
	pages.push_back(page1);
	
	for (int i=0; i<pages.size(); i++)
	{
		cout << "page " << i << endl;
		
		for (int j=0; j<pages[i].brushPtrs.size(); j++)
		{
			
			cout << "brush " << j << ": " << pages[i].brushPtrs[j] << endl;
		}
	}
	
	int myNumber = 10;
	int * myIntPtr = &myNumber;
	cout << "my number: " << myNumber << ", address: " << myIntPtr << endl;
	
	

}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofPolyline line;
	
	float animTime = ofGetElapsedTimef() - animStartTime;
	float linePct = ofMap(animTime, 0, 2., 0, 1.);
	
	spongebob.pos = line.getPointAtPercent(linePct);

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	pages[0].currentBrush->draw(ofGetMouseX(), ofGetMouseY());
	
//	pages[1].currentBrush->draw(ofGetMouseX(), ofGetMouseY());
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	if (key == 'c')
	{
		pages[0].currentBrush = pages[0].brushPtrs[0];
	}
	else if (key == 'r')
	{
		pages[0].currentBrush = pages[0].brushPtrs[1];
	}
	
	if (key == '0')
	{
		pageNum = 0;
	}

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
