#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	/*
	 POINTERS:
	 ---------
	 
	 The variables in your app are stored temporarily in your computer's memory ("RAM").
	 Each variable has its own "address" in memory.  This address is a number, like a mailbox number.
	 
	 In C++, we can store the addresses of our variables using special types called "pointers".
  
	 To declare a pointer, we write the type, then '*'
	 (e.g. int * myIntPtr)
  
	 To get the address of a variable, we use the syntax '&variable'
	 (e.g. &myInt = address of myInt)
  
	 */
	
	
	// here's an example
	
	
	int myInt		= 10;
	int * myIntPtr	= &myInt;		// int pointer = &(address of) myInt
	
	cout
	<< "the value of 'myInt' is: " << myInt << endl
	<< "the memory address of 'myInt' is: " << myIntPtr << endl;
	
	

	
	// we can also allocate an array at a pointer address:
	
	// int * intArray;
	
	intArray = new int[arraySize];	// construct a 20 int array
	
	for (int i=0; i<arraySize; i++)
	{
		intArray[i] = ofRandom(0,255);
	}


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	float w = ofGetWidth();
	float h = ofGetHeight() / float(arraySize);
	
	for (int i=0; i<arraySize; i++)
	{
		
		int & val		= intArray[i];		// reference to value
		int * ptr		= &intArray[i];		// pointer to address
		
		
		ofSetColor(val);
		ofDrawRectangle(0,i*h,w,h);
		
		stringstream label;
		label << "intArray[" << i << "]:\t" << val << "\t" << ptr;
		
		ofDrawBitmapStringHighlight(label.str(), 100,h*(i+.5));
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	for (int i=0; i<arraySize; i++)
	{
		intArray[i] = ofRandom(0,255);
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
