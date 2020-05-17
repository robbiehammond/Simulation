#pragma once
#include <SFML/Graphics.hpp>
#include "Colony.h"
#ifndef PERSON
#define PERSON

class Person
{
public:
	Person(float startX, float startY, Colony _col);
	sf::Color color;
	sf::Vector2f position;
	sf::CircleShape shape;
	
	Colony myCol;
	//do something with this
	bool found;
	//eventually add?
	//bool targetFound;
	//add a "can move" variable based on the map - maybe just a list of valid coordinates
	int radius;
	int health;
	float speed = 0.2f;
	int damage;

	sf::FloatRect getPosition();
	float distance(Person& other);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void updateRadius(float radius);

private:

	
};
#endif
