#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes/City.h"

int main() {
	City city{ 0.0f, 0.0f };
	City city2{ 100.0f, 100.0f };
	city.link(&city2);
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800), "Traveling Salesman", sf::Style::Close);
	while (window.isOpen()) {
		window.clear();
		window.draw(city);
		window.display();
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed: {
				window.close();
			} break;
			case sf::Event::KeyPressed: {
				switch (e.key.code) {
				case sf::Keyboard::Escape: {
					window.close();
				} break;
				}
			} break;
			}
		}
	}
	return 0;
}