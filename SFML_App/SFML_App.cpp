#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>

// headers
#include "Borders.h"
#include "Player.h"

// Use the namespaces sf and std
using namespace sf;
using namespace std;

// Variables:
vector<RectangleShape*> rects;

float win_w;
float win_h;

unsigned int initial_Width = 800;
unsigned int initial_Height = 600;

// Transformation details:
float x = 0.f;
float y = 0.f;

// Creates the corners
Borders borders = Borders();

// Functions

// Create rectangles
void static addRectangles(vector<RectangleShape*>& rects, int num, float width, float height) {
	for (int i = 0; i < num; i++)
		rects.push_back(new RectangleShape({ width, height }));
}



int main() {
	// Create the window	
	RenderWindow mainWindow(VideoMode({ initial_Width, initial_Height }), "My First App"); // Note VideoMode takes Unsigned ints
	
	// Create Game Objects
	Player player = Player( initial_Width, initial_Height );

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

		}

		// Window width and height:
		win_w = static_cast<float>(mainWindow.getSize().x);
		win_h = static_cast<float>(mainWindow.getSize().y);

		//// Keyboard: NOTE: These are input types and NOT events!

		// Fixes the Color error with resizing 
		mainWindow.clear(Color(175, 175, 175)); // Make sure your capitalization is right!

		rects[0]->setOrigin({ 200.f, 100.f });
		rects[0]->setFillColor(Color(127, 25, 123));
		rects[0]->setOutlineThickness(15.f);
		rects[0]->setPosition({ win_w / 2 + x, win_h / 2 + y });
		//rects[0]->setRotation(degrees(30.f));
		rects[0]->setScale({ win_w / 1600.f, win_w / 1200.f });

		borders.realign(win_w, win_h);
		borders.drawBorder(mainWindow);

		/*for (unsigned int i = 0; i < rects.size(); i++) {
			mainWindow.draw(*rects[i]);
		}*/

		player.DrawPlayer(mainWindow);
		mainWindow.display();

	}


	return 0; // this is part of the default main for C++
}