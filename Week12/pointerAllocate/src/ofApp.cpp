#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	cout << "POINTER BASICS:" << endl;

	/* 
	
	 pointers are memory address numbers, like mailbox numbers.

	 when using pointers, we need to specify the type of value the "mailbox" contains.

	 declare a pointer using '*' after the type name, like:

	 */

	int * pointer = nullptr;		// this address will contain an int value

	// we assign the pointer to 'nullptr' to mark that it is empty
	// when a pointer is nullptr, it HAS NO ADDRESS - the address is 'null' - 0, or nullptr:
	
	cout << "int pointer created, with 'nullptr' address: " << pointer;


	// for pointers to be valid, we need to assign (=) them to a useful address

	// there are a few ways to do that...


	// you can construct a permanent new object in memory with 'new' keyword and Constructor() function

	pointer = new int(6);	// create the number 6 in memory at a new address


	// to access the value of a pointer, we use '*' before the pointer name.
	// this is called "dereferencing" the pointer:

	int value = *pointer;		// get the value at pointer address ("dereference")

	cout << "int pointer assigned to address: " << pointer << ", with value: " << value << endl;


	// let's say we're done with this pointer / memory space.
	// we need to now "free" the memory we allocated (to store '6'), so that it's available to our app again for other use

	// to free the pointer memory, we use the 'delete' keyword:

	delete pointer;			// ALWAYS follow a 'new' with a 'delete' later to free the memory 
							// or you will have a MEMORY LEAK :( and may run out of memory!

	// after we 'delete', the pointer address remains the same, but the contents are gone!

	cout << "int pointer deleted, address is still: " << pointer << ", but value is now: " << *pointer << endl;		// *pointer (dereference) to get value

	// we should now set the pointer to nullptr to mark that it is invalid

	pointer = nullptr;

	
	// NOTE that if we try to access the value of a null pointer, our app will crash!

	// uncomment this line to crash your app:

	// cout << "int pointer is null, trying to get value: " << *pointer;


	
	// you can also assign the pointer to the address of a variable
	// using '&' address-of operator:

	int variable = 10;

	pointer = &variable;

	cout << "int pointer assigned to address: " << pointer << ", with value: " << *pointer << endl;


	// in this case you DON'T need to 'delete' the pointer to free the memory

	// the memory will be freed automatically when the variable goes "out of scope" ( we reach the '}' below )

	// BUT be aware that the pointer will be invalid once the variable leaves scope!


	// now...

	// let's construct our rectangle ptr:

	rectPtr = new ofRectangle(0,0,400,400);

}

//--------------------------------------------------------------
void ofApp::update(){

	// let's update our rectangle's size

	float size = 400.f + ofSignedNoise(ofGetElapsedTimef()) * 100.f;

	// to access the internals of the ofRectangle at our pointer address
	// we can use the '->' operator:

	rectPtr->setSize(size,size);

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawBitmapStringHighlight("be sure to check the console also for some more pointer examples", 20, 20);



	ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);


	ofPushMatrix();

	ofRotateY(ofGetElapsedTimef() * 20.f);

	ofSetRectMode(OF_RECTMODE_CENTER);	// draw from center


	// let's draw our rectangle, by using the value of the pointer as an argument

	ofDrawRectangle(*rectPtr);

	ofPopMatrix();


	ofSetRectMode(OF_RECTMODE_CORNER);

	// let's print some info on our rectangle pointer:

	stringstream info;
	info << "rectPtr address: " << rectPtr << endl;		// prints hex address
	info << "rectPtr value: " << *rectPtr << endl;		// prints the pointer value
	info << "rect area: " << rectPtr->getArea() << endl;	// access the pointer's object
	ofDrawBitmapStringHighlight(info.str(), -100, 0);


}

// exit() is automatically called when the app is closing!

void ofApp::exit()
{
	// free the rectangle memory!
	delete rectPtr;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
