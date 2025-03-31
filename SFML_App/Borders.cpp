#include "Borders.h"
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;


// Default constructor: 200 : 100 with origins set to corners
Borders::Borders() {
	topLeft = new RectangleShape({ 200.f, 100.f });
	topRight = new RectangleShape({ 200.f, 100.f });
	bottomLeft = new RectangleShape({ 200.f, 100.f });
	bottomRight = new RectangleShape({ 200.f, 100.f });

	topSide = new RectangleShape({ 200.f, 100.f });
	rightSide = new RectangleShape({ 100.f, 200.f });
	leftSide = new RectangleShape({ 100.f, 200.f }); 
	bottomSide = new RectangleShape({ 200.f, 100.f });

	topRight->setOrigin({ 200.f, 0.f });
	bottomLeft->setOrigin({ 0.f, 100.f });
	bottomRight->setOrigin({ 200.f, 100.f });

	topSide->setOrigin({ 100.f, 0.f });
	leftSide->setOrigin({ 0.f, 100.f });
	rightSide->setOrigin({ 100.f, 100.f });
	bottomSide->setOrigin({ 100.f, 100.f });

}

// Methods:

// Aligns the rectangles to the corners
void Borders::realign_b(float win_w, float win_h) {
	topRight->setPosition({ win_w, 0.f });
	bottomLeft->setPosition({ 0.f, win_h });
	bottomRight->setPosition({ win_w, win_h });

	topSide->setPosition({ win_w / 2, 0.f });
	leftSide->setPosition({ 0.f, win_h / 2 });
	rightSide->setPosition({ win_w, win_h/2 });
	bottomSide->setPosition({ win_w / 2, win_h });

}

// Draws the Borders (uses the memory address of the RenderWindow
void Borders::drawBorder(sf::RenderWindow& win) {
	//// Draws to the window
	win.draw(*topLeft);
	win.draw(*topRight);
	win.draw(*bottomLeft);
	win.draw(*bottomRight);
	win.draw(*topSide);
	win.draw(*rightSide);
	win.draw(*leftSide);
	win.draw(*bottomSide);

}