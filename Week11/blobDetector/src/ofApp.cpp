#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	video.load("video.mp4");
	video.play();
	
	float vidArea = video.getWidth() * video.getHeight();
	
	gui.setup();
	gui.add( threshold.setup("threshold", 122, 0, 255));
	gui.add( maxBlobs.setup("max # blobs", 10, 1, 20));

}

//--------------------------------------------------------------
void ofApp::update(){
	
	video.update();
		
	if (video.isFrameNew())
	{
		
		// threshold the image
		colorImg.setFromPixels(video.getPixels());
		threshImg = colorImg;
		threshImg.threshold(threshold);
		
		blobs.clear();
		
		blobFinder.findContours(threshImg, 0, 640*480, maxBlobs, false);
		
		for (int i=0; i<blobFinder.nBlobs; i++)
		{
			// copy the points into an ofPath
			
			auto& pts = blobFinder.blobs[i].pts;
			
			ofPath path;
			path.moveTo(pts[0]);
			
			for (int j=1; j<pts.size(); j++)
			{
				path.lineTo(pts[j]);
			}
			
			path.lineTo(pts[0]);	// complete the loop
			path.close();
			
			blobs.push_back( path );
			
		}
		
	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(255);
	
	video.draw(0,0);
	
	// draw blobs manually
	
	for (int i=0; i<blobs.size(); i++){
		
		float hue = ofMap(i, 0, blobs.size(), 0, 255);
		blobs[i].setColor( ofColor::fromHsb(hue, 255, 255, 200));
		
		blobs[i].draw();
	}
	
	
	threshImg.draw(640,0);
	
	blobFinder.draw(640,0);	// draw blobs auto

	
	gui.draw();
	
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
