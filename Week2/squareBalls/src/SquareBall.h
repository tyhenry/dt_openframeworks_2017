#pragma once

#include "Ball.h"
#include "ofMain.h"

class SquareBall : public Ball {  // SquareBall class **inherits** from Ball class

public:

	SquareBall();

	void draw(); // this will **override** the draw function inherited from Ball

};