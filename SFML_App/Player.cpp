#include <iostream>
#include <SFML/Graphics.hpp>

#include "Inputs.h"
#include "Player.h"


using namespace sf;
using namespace std;

// Default constructor:
	// Uses a RectangleShape (100, 100) as a sprite with default speed of 0.25 located at the centre
Player::Player(float win_w, float win_h) {
	width_p = 100.f;
	height_p = 100.f;
	spd_x = 0.25;
	spd_y = 0.25;
	playerSprite = new RectangleShape({ width_p, height_p });

	origin_p = { width_p / 2, height_p / 2 };
	position_p = { win_w/2, win_h/2 }; // This is starting location at centre
	
	playerSprite->setOrigin(origin_p);
	playerSprite->setPosition(position_p);

	playerSprite->setFillColor(Color(125, 65, 150));
	playerSprite->setOutlineThickness(5.f);
	
}

//Player::Player(sf::RectangleShape playerSprite, float width, float height, float spd_x, float spd_y) {
//	cout << "WIP";
//}
//
//
//// Movement
//void playerMovement() {
//	cout << "WIP";
//}

// Draws the player onto the window:
void Player::DrawPlayer(RenderWindow& win) {
	win.draw(*playerSprite);

}
