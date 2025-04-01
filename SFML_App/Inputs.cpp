#include <iostream>
#include <SFML/Graphics.hpp>

#include "PlayerData.h"

//#include "Inputs.h"

using namespace sf;
using namespace std;

// Movement Functions:
	// Recall, static functions can be referenced without and object and hence do not have to be associated with class::Functionname

// This function handles movment 
sf::Vector2f static movement_gen(PlayerData& data_p) { // fix this : standalone cpp file for functs
	// Checks if a key has been pressed:
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		if (data_p.position_p[1] - data_p.spd_y > 0)
			data_p.position_p[1] -= data_p.spd_y;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		if (data_p.position_p[0] - data_p.spd_x > 0)
			data_p.position_p[0] -= data_p.spd_x;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		if (data_p.position_p[0] + data_p.spd_x < data_p.win_w)
			data_p.position_p[0] += data_p.spd_x;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		if (data_p.position_p[1] + data_p.spd_y < data_p.win_h)
			data_p.position_p[1] += data_p.spd_y;
	}
	return { data_p.position_p[0], data_p.position_p[1] };
}

// This function handles Window Collisions

