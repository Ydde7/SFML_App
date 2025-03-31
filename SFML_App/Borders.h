#ifndef BORDERS_H
#define BORDERS_H

#include <SFML/Graphics.hpp>

struct Borders {
	sf::RectangleShape* topLeft;
	sf::RectangleShape* topRight;
	sf::RectangleShape* bottomLeft;
	sf::RectangleShape* bottomRight;

	sf::RectangleShape* topSide;
	sf::RectangleShape* rightSide;
	sf::RectangleShape* leftSide;
	sf::RectangleShape* bottomSide;

	// Constructors
	Borders();

	// Methods
	void realign_b(float win_w, float win_h);

	void drawBorder(sf::RenderWindow& win);

};

#endif
