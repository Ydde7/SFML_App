#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

#include "Inputs.cpp"
#include "Player.h"
#include "PlayerData.h"


using namespace sf;
using namespace std;

// Default constructor:
	// Uses a RectangleShape (100, 100) as a sprite with default speed of 0.25 located at the centre
Player::Player(float win_w, float win_h) {
	data_p = PlayerData( win_w, win_h, 0.2, 0.2, 100.0, 100.0, new RectangleShape({100.f, 100.f}) );
	cout << "Player added" << endl;
}

//Player::Player(sf::RectangleShape playerSprite, float width, float height, float spd_x, float spd_y) {
//	cout << "WIP";
//}
//
//
// 



// Movement: Moves the player around the screen using the WASD keys at the player's registered speed
void Player::movement_p(float win_w, float win_h) {

	// Movement:
	sf::Vector2f coords = movement_gen(data_p);
	data_p.position_p[0] = coords.x;
	data_p.position_p[1] = coords.y;
	data_p.playerSprite->setPosition(coords);
}

// Draws the player onto the window:
void Player::DrawPlayer(sf::RenderWindow& win) {
	//updateHBox();

	int count = 0;
	count++;
	if (count > 60) {
		cout << "Player Drawn" << endl;
		count = 0;
	}

	// Update height of window 
	data_p.updateCoords_pd(win.getSize().x, win.getSize().y);

	// Update player sprite values
	data_p.playerSprite->setOrigin({ data_p.origin_p[0], data_p.origin_p[1] }); // For whensprite resizing is added
	data_p.playerSprite->setPosition({ data_p.position_p[0], data_p.position_p[1] });

	win.draw(*data_p.playerSprite);
	
}



// Updates the area fo the player:
//void Player::updateHBox() {
//	hBox = playerSprite->getSize().x * playerSprite->getSize().y;
//}


