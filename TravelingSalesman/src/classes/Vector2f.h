#pragma once
#include <SFML/Graphics.hpp>

struct Vector2f {
	float x{ 0.0f };
	float y{ 0.0f };

	Vector2f(float x, float y) :x{ x }, y{ y } {
		
	}

	Vector2f operator+=(const Vector2f& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2f operator-=(const Vector2f& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	static float magnitude(const Vector2f& v) {
		return sqrt(v.x * v.x + v.y * v.y);
	}

	sf::Vector2f toSF() {
		return sf::Vector2f(x, y);
	}
};

inline Vector2f operator-(const Vector2f l, const Vector2f& r) {
	return Vector2f(l.x - r.x, l.x - r.y);
}

inline Vector2f operator*(const float s, const Vector2f& v) {
	return Vector2f{ v.x * s, v.y * s };
}

inline Vector2f operator*(const Vector2f& v, const float s) {
	return Vector2f{ v.x * s, v.y * s };
}

inline Vector2f operator/(const Vector2f& v, const float s) {
	return Vector2f{ v.x / s, v.y / s };
}