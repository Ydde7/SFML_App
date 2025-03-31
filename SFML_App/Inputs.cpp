#include <iostream>
#include <SFML/Graphics.hpp>

//#include "Inputs.h"

using namespace sf;
using namespace std;

// Movement Functions:
	// Recall, static functions can be referenced without and object and hence do not have to be associated with class::Functionname

// This function handles movment 
sf::Vector2f static movement_gen(float win_w, float win_h, float x, float y, float spd_x, float spd_y) { // fix this : standalone cpp file for functs
	// Checks if a key has been pressed:
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		if (y - spd_y > 0)
			y -= spd_y;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		if (x - spd_x > 0)
			x -= spd_x;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		if (x + spd_x < win_w)
			x += spd_x;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		if (y + spd_y < win_h)
			y += spd_y;
	}
	return { x,y };
}

// This function handles Window Collisions

