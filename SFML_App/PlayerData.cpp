#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

#include "PlayerData.h"

using namespace sf;
using namespace std;

// Default constructor assumes a window of 800x600
PlayerData::PlayerData() {
	win_w = 800;
	win_h = 600;
	spd_x = 0.2;
	spd_y = 0.2;
	playerSprite = new RectangleShape({ 100.f, 100.f });

	width_p = 100.0;
	height_p = 100.0;

	origin_p[0] = width_p / 2;
	origin_p[1] = height_p / 2;

	//// This is starting location at centre
	position_p[0] = win_w / 2;
	position_p[1] = win_h / 2;

	playerSprite->setOrigin({ origin_p[0], origin_p[1] });
	playerSprite->setFillColor(Color(207, 245, 210));

	
	cout << "Default used" << endl;
}

PlayerData::PlayerData(float win_w, float win_h, float spd_x, float spd_y, float width_p, float height_p, sf::RectangleShape* playerSprite) {
	this->win_w = win_w;
	this->win_h = win_h;
	this->spd_x = spd_x;
	this->spd_y = spd_y;
	this->playerSprite = playerSprite;

	this->width_p = width_p;
	this->height_p = height_p;

	origin_p[0] = width_p / 2;
	origin_p[1] = height_p / 2;

	//// This is starting location at centre
	position_p[0] = win_w / 2;
	position_p[1] = win_h / 2;

	this->playerSprite->setOrigin({ origin_p[0], origin_p[1] });
	this->playerSprite->setFillColor(Color(157, 75, 86));

	cout << "Parameterized used" << endl;
}

// Updates the position and origin of the player:
void PlayerData::updateCoords_pd(float win_w, float win_h)  {
	float oldDim[2] = { this->win_w, this->win_h };

	this->win_w = win_w;
	this->win_h = win_h;

	position_p[0] -= oldDim[0] / 2;
	position_p[1] -= oldDim[1] / 2;

	position_p[0] += win_w / 2;
	position_p[1] += win_h / 2;

}
