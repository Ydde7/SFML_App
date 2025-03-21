#include <SFML/Graphics.hpp>
#include <iostream>


// Use the namespaces sf and std
using namespace sf;
using namespace std;


int main() {
	// Create the window	
	RenderWindow mainWindow(VideoMode({ 800,600 }), "My First App");
	
	RectangleShape myRectangle({ 400.f, 200.f }); // Creates a rectangle shape

	// The main loop:
	while (mainWindow.isOpen()) {

		// Deals with closing the window
			// Event is an "optional" variable that stores the polled window event
		while (optional event = mainWindow.pollEvent()) {

			if (event->is<Event::Closed>()) { // Deals with the case of window closure

				mainWindow.close();

			}
			if (event->is<Event::Resized>()) {

				View view(FloatRect({ 0.f, 0.f }, Vector2f(mainWindow.getSize()))); // Not center Defined
			
				//View view({400.f, 300.f}, Vector2f(mainWindow.getSize())); // Centers the rectangle (the floats are the rectangle's position)
				mainWindow.setView(view);
			}
		}

		// Fixes the Color error with resizing 
		mainWindow.clear(Color(225, 225, 225)); // Make sure your capitalization is right!

		// Shape Stuff:
		myRectangle.setOrigin({ 200.f, 100.f }); // Sets the origin by realizing the centre is half the height and width

		myRectangle.setFillColor(Color(127, 25, 123));
		myRectangle.setOutlineThickness(15.f);
		myRectangle.setPosition({ 400.f, 300.f });
		myRectangle.setRotation(degrees(30.f));
		
		// Draws to the window
		mainWindow.draw(myRectangle);
		mainWindow.display();

	}


	return 0; // this is part of the default main for C++
}