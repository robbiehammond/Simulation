#include <SFML/Graphics.hpp>
#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(float startX, float startY, Colony _col, Map _curMap)
	: myCol(_col), curMap(_curMap.m)
{
	found = false;

	//these are mutatable
	health = 10;
	radius = health;
	damage = 1 + (rand() % 10);
	
	position.x = startX;
	position.y = startY;
	color = myCol.color;
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setRadius(radius);
	myCol = _col;
}



//checking the same bounds twice here, do it only once by using a variable
void Person::moveUp()
{
	float temp = position.y;
	temp -= speed;
	//check if where they're trying to move is a valid position
	if (checkBounds(position.x, temp))
	{
		position.y -= speed;
		shape.setPosition(position);
	}
	//if it's not, push them backwards and nudge them toward the center
	if (!checkBounds(position.x, temp))
	{
		if (position.x < 640) {
			position.x += speed;
			shape.setPosition(position);
		}
		else
		{
			position.x -= speed;
			shape.setPosition(position);
		}
	}
	//so they don't get stuck, move them in a perpendicular direction as well
	while (!checkBounds(position.x, position.y)) {
		position.y += speed;
		shape.setPosition(position);
		
	}
}

void Person::moveDown()
{
	float temp = position.y;
	temp += speed;
	if (checkBounds(position.x, temp)) {
		position.y += speed;
		shape.setPosition(position);
	}
	if (!checkBounds(position.x, temp))
	{
		if (position.x < 640) {
			position.x += speed;
			shape.setPosition(position);
		}
		else
		{
			position.x -= speed;
			shape.setPosition(position);
		}
	}
	
	while (!checkBounds(position.x, position.y)) {
		position.y -= speed;
		shape.setPosition(position);
		
	}
}

void Person::moveLeft()
{
	float temp = position.x;
	temp -= speed;
	if (checkBounds(temp, position.y)) {
		position.x -= speed;
		shape.setPosition(position);
	}
	if (!checkBounds(temp, position.y))
	{
		if (position.y < 360) {
			position.y += speed;
			shape.setPosition(position);
		}
		else
		{
			position.y -= speed;
			shape.setPosition(position);
		}
	}
	
	while (!checkBounds(position.x, position.y)) {
		position.x += speed;
		shape.setPosition(position);
		
	}
}


void Person::moveRight()
{
	
	float temp = position.x;
	temp += speed;
	if (checkBounds(temp, position.y)) {
		position.x += speed;
		shape.setPosition(position);
	}
	if (!checkBounds(temp,position.y))
	{
		if (position.y < 360) {
			position.y += speed;
			shape.setPosition(position);
		}
		else
		{
			position.y -= speed;
			shape.setPosition(position);
		}
	}
		
	while (!checkBounds(position.x, position.y)) {
		position.x -= speed;
		shape.setPosition(position);
		
	}
}


float Person::distance(Person& other)
{
	return sqrt(pow(other.position.x - this->position.x, 2) + pow(other.position.y - this->position.y, 2) * 1.0);
}


void Person::updateRadius(float _radius)
{
	radius = _radius;
	shape.setRadius(radius);

}

void Person::updateHealth(float _health)
{
	health = _health;
	updateRadius(health);
}

//returns if the bounds are valid 
bool Person::checkBounds(float x, float y)
{
	float x_coord = position.x;
	float y_coord = position.y;
	MapSelection map = curMap.m;

	//only need to loop through x_restrictions, because x and y restrictions are the same size
	for (int i = 0; i < curMap.x_restrictions.size(); i++) {
		switch (map)
		{
		case Map1:
			if (x_coord >= std::get<0>(curMap.x_restrictions[i]) && x_coord <= std::get<1>(curMap.x_restrictions[i]) && y_coord >= std::get<0>(curMap.y_restrictions[i]) && y_coord <= std::get<1>(curMap.y_restrictions[i])) {
				return false;
			}
			break;
		case Map2:
			if (x_coord >= std::get<0>(curMap.x_restrictions[i]) && x_coord <= std::get<1>(curMap.x_restrictions[i]) && y_coord >= std::get<0>(curMap.y_restrictions[i]) && y_coord <= std::get<1>(curMap.y_restrictions[i])) {
				return false;
			}
			break;
		case Map3:
			break;
		default:
			return true;
		}
	}
	//if that for loop is skipped altogether, that means there are no restrictions, so return true bc all coordinates are valid
	return true;
}