#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <SFML/Graphics.hpp>
#include <array>

//// To add: health, size, sprite, ...
//float width_p;
//float height_p;
//float spd_x;
//float spd_y;
//float origin_p[2];
//float position_p[2];
//sf::RectangleShape* playerSprite; // change to a sprite later

struct PlayerData {
	float win_w;
	float win_h;
	float width_p;
	float height_p;
	float spd_x;
	float spd_y;

	float origin_p[2] = {0.0, 0.0}, position_p[2] = {0.0, 0.0};

	sf::RectangleShape* playerSprite;

	// Constructor:
	PlayerData();

	PlayerData(float win_w, float win_h, float spd_x, float spd_y, float width_p, float height_p, sf::RectangleShape* playerSprite);

	// Mehthods:
	void updateCoords_pd(float win_w, float win_h) ;

};


#endif