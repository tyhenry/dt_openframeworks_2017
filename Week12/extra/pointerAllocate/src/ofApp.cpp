#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	int * myIntPtr = new int(6);

	
	shared_ptr<int> mySharedIntPtr ( new int(7) );
	
	{
	shared_ptr<int> myOtherPtr = mySharedIntPtr;
	
	cout << "num refs to ptr: " << mySharedIntPtr.use_count() << endl;
	}
	cout << "num refs to ptr: " << mySharedIntPtr.use_count() << endl;

	
	cout
		<< "myIntPtr address:\t" << myIntPtr << endl
		<< "myIntPtr value:\t" << *myIntPtr << endl

		<< "mySharedIntPtr address:\t" << mySharedIntPtr << endl
		<< "mySharedIntPtr value:\t" << *mySharedIntPtr << endl;
	
	
	rect = ofRectangle(200,200,200,200);
	animStart = ofGetElapsedTimef();
	
	img.load("myImage.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	
	float animProgress = ofGetElapsedTimef() - animStart;

	alpha = ofMap(animProgress, 2, animDur+2, 255, 0, true);
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	fbo.begin();
	ofSetColor(0,0,255,alpha);
	ofDrawRectangle(rect);
	fbo.end();
	
	ofImage img;
	fbo.readToPixels(img.getPixels());
	img.mirror(false,true);
	img.update();

//	ofTexture imgTex;
//	imgTex.draw(0,0,100,100);
	
	ofPlanePrimitive plane;
	plane.set(100,100,10,10);
	
	
	
	img.bind();
	plane.draw();
	img.unbind();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	animStart = ofGetElapsedTimef();

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
