//
//  ParticleSystem.cpp
//  ParticleSystem
//
//  Created by Tyler on 10/5/17.
//
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(ofVec3f _pos){
	pos = _pos;
	lifespan = 10.;
}

void ParticleSystem::update(ofVec3f force, float timeDiff){ // time elapsed since last frame
	
	// create more particles based on lifespan
	int nNewParticles = lifespan;
	
	for (int i=0; i<nNewParticles; i++){
		Particle particle(pos);
		particles.push_back(particle);
	}
	
	// update particles
	
	for (int i=0; i<particles.size(); i++){
		particles[i].applyForce(force);
		particles[i].update(timeDiff);
	}
	
	// erase particles until we have a manageable size
	while (particles.size() > 1000){
		particles.erase(particles.begin());
	}
	
	lifespan -= timeDiff;
	if (lifespan < 0) lifespan = 0;

}

void ParticleSystem::draw(){
	for (int i=0; i<particles.size(); i++){
		particles[i].draw();
	}
}