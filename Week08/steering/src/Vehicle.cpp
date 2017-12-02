#include "Vehicle.h"


void Vehicle::update() {
	
    vel += acc;
    vel.limit(maxSpeed);	// limit our speed
	
    pos += vel;

	acc *= 0;
    
}

void Vehicle::applyForce(ofVec3f force) {
	force.limit(maxForce);
    acc += force;
}

void Vehicle::draw() {
    
    ofPushMatrix();
    ofTranslate(pos);
    float rot = atan2( vel.y, vel.x );
    ofRotate(ofRadToDeg(rot));
    
    ofSetColor(255);
    ofDrawTriangle( 0,0, -40,-10, -40,10);
    ofPopMatrix();
}


void Vehicle::seek(ofVec3f target) {
	
	ofVec3f desired = target - pos;
	
	float distance = desired.length();
	desired.normalize();
	
	// for arriving smoothly:

	float speed = ofMap(distance, 0,100, 0,maxSpeed, true);
	desired *= speed;
	
	// steer force pushes velocity towards desired path
	ofVec2f steer = desired - vel;
	
	steer.limit(maxForce);
	applyForce(steer);
}



