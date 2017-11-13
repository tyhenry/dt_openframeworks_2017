#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	
	vid.listDevices();
	vid.setup(640, 480);
	
	// allocate our images
	
	alphaImg.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
	colorImg.allocate(640, 480);
	grayImg.allocate(640, 480);
	grayBg.allocate(640, 480);
	grayDiff.allocate(640, 480);
	grayThresh.allocate(640, 480);
	
	
	gui.setup();
	gui.add( threshold.setup("threshold", 122, 0, 255));
	
	// capture background from first frame of camera
	bCaptureBg = true;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	vid.update();
	
	if (vid.isFrameNew())
	{
		
		colorImg.setFromPixels(vid.getPixels());	// get color pix
		grayImg = colorImg;							// convert grayscale
		
		if (bCaptureBg)
		{
			grayBg = grayImg;			// grab a new background snapshot
			bCaptureBg = false;			// reset until user presses key again
		}
		
		grayDiff.absDiff(grayImg, grayBg);		// difference between new frame and background
		
		grayThresh = grayDiff;
		grayThresh.threshold(threshold);
		
		
		// fill in alpha channel based on threshold image
		
		alphaImg.setFromPixels(colorImg.getPixels());
		alphaImg.setImageType(OF_IMAGE_COLOR_ALPHA);	// add alpha channel!!
		
		for (int i=3; i<alphaImg.getPixels().size(); i+=4)	// every 4 channels (r,g,b,a)
		{
			alphaImg.getPixels()[i] = grayThresh.getPixels()[i/4];	// copy gray value to alpha
		}
		
		alphaImg.update();
		
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	alphaImg.draw(0,0,640,480);
	
	ofDrawBitmapStringHighlight("press any key to capture background", 20, 480);
	
	ofPushMatrix();
	ofTranslate(640,0);
	
	grayBg.draw		(0,0,		320,240);	// top left		- background
	grayImg.draw		(320,0,		320,240);	// top right	- grayscale
	grayDiff.draw	(0,240,		320,240);	// bot. left	- difference
	grayThresh.draw	(320,240,	320,240);	// bot. right	- thresholded
	
	ofDrawBitmapStringHighlight("background - press any key!", 20,20);
	ofDrawBitmapStringHighlight("grayscale", 340,20);
	ofDrawBitmapStringHighlight("difference", 20,260);
	ofDrawBitmapStringHighlight("thresholded", 340,260);
	
	ofPopMatrix();
	
	gui.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	bCaptureBg = true;
	
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
