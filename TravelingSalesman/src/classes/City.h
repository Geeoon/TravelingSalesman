#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Vector2f.h"

class City : public sf::Drawable {
public:
	City(Vector2f p);
	City(float x, float y);
	float distanceTo(const City& city) const;
	void link(City* city);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::CircleShape shape;
	City* next = nullptr;
	Vector2f position;
};