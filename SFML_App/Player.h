#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// Player should have:
	// Sprite
	// Movement
	// Animation

class Player {
	// To add: health, size, sprite, ...
	float width_p;
	float height_p;
	float spd_x;
	float spd_y;
	sf::Vector2f origin_p;
	sf::Vector2f position_p;
	sf::RectangleShape* playerSprite; // change to a sprite later

	public:
		// Goals: 3 constructors:
			// Default, Position, Full customization

		Player( float win_w, float win_h); 
		//Player( sf::RectangleShape playerSprite, float width_p, float height_p, float spd_x, float spd_y );
	
		//// Methods:
		///*sf::VectorgetWindowSize(float width_w);*/

		//void playerMovement();
		
		//Update Position(float win_w, float win_h); In the loop to deal with resizing

		void DrawPlayer(sf::RenderWindow& win);

	};

#endif
