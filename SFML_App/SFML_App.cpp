#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>

#include "Borders.h"

// Use the namespaces sf and std
using namespace sf;
using namespace std;

// Variables:
vector<RectangleShape*> rects;

// Transformation details:
float x = 0.f;
float y = 0.f;

// Creates the corners
Borders borders = Borders();

// Functions

// Create rectangles
void addRectangles(vector<RectangleShape*>& rects, int num, float width, float height) {
	for (int i = 0; i < num; i++)
		rects.push_back(new RectangleShape({ width, height }));
}



int main() {
	// Create the window	
	RenderWindow mainWindow(VideoMode({ 800,600 }), "My First App");



	//RectangleShape myRectangle({ 400.f, 200.f }); // Creates a rectangle shape
	addRectangles(rects, 1, 400.f, 200.f);


	// The main loop:
	while (mainWindow.isOpen()) {



		// Deals with closing the window
			// Event is an "optional" variable that stores the polled window event
		while (optional event = mainWindow.pollEvent()) {

			if (event->is<Event::Closed>()) { // Deals with the case of window closure

				mainWindow.close();

			}
			else if (event->is<Event::Resized>()) {

				View view(FloatRect({ 0.f, 0.f }, Vector2f(mainWindow.getSize()))); // Not center Defined

				// Note: This code breaks the alignment for border
			//View view({400.f, 300.f}, Vector2f(mainWindow.getSize())); // Centers the rectangle (the floats are the rectangle's position)
				mainWindow.setView(view);
			}

			//// Keyboard: NOTE: These are input types and NOT events!
					
			// Checks if a key has been pressed:
			if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
				y -= 15;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
				x -= 15;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
				x += 15;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
				y -= 15;
			}
		}

		// Window width and height:
		float win_w = static_cast<float>(mainWindow.getSize().x);
		float win_h = static_cast<float>(mainWindow.getSize().y);

		// Fixes the Color error with resizing 
		mainWindow.clear(Color(175, 175, 175)); // Make sure your capitalization is right!

		rects[0]->setOrigin({ 200.f, 100.f });
		rects[0]->setFillColor(Color(127, 25, 123));
		rects[0]->setOutlineThickness(15.f);
		rects[0]->setPosition({ win_w / 2 + x, win_h / 2 + y });
		rects[0]->setRotation(degrees(30.f));
		rects[0]->setScale({ win_w / 1600.f, win_w / 1200.f });

		borders.realign(win_w, win_h);

		borders.drawBorder(mainWindow);

		for (unsigned int i = 0; i < rects.size(); i++) {
			mainWindow.draw(*rects[i]);
		}

		mainWindow.display();

	}


	return 0; // this is part of the default main for C++
}