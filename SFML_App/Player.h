#ifndef PLAYER_H
#define PLAYER_H

#include <array>

#include <SFML/Graphics.hpp>
#include "PlayerData.h"


// Player should have:
	// Sprite
	// Movement
	// Animation

class Player {
	//// To add: health, size, sprite, ...
	//float width_p;
	//float height_p;
	//float spd_x;
	//float spd_y;
	//float origin_p[2];
	//float position_p[2];
	//sf::RectangleShape* playerSprite; // change to a sprite later

	PlayerData data_p;

	// Stats
	//float hBox;

	public:
		// Goals: 3 constructors:
			// Default, Position, Full customization

		Player( float win_w, float win_h); 
		//Player( sf::RectangleShape playerSprite, float width_p, float height_p, float spd_x, float spd_y );
	
		//// Methods: 

		void movement_p(float win_w, float win_h);
		

		// Updating player stats:
		//void updateHBox();
		//Update Position(float win_w, float win_h); In the loop to deal with resizing

		
		void DrawPlayer(sf::RenderWindow& win);

	};

#endif
