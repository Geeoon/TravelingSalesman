#include "City.h"

City::City(Vector2f p) : position{ p } {
	shape.setRadius(3.0f);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setPosition(position.toSF());
}

City::City(float x, float y) : position{ x, y } {
	shape.setRadius(3.0f);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setPosition(position.toSF());
}

void City::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
	if (next) {
		target.draw(*next);
	}
}

void City::link(City* city) {
	next = city;
}

float City::distanceTo(const City& city) const {
	return Vector2f::magnitude(this->position - city.position);
}