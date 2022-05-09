#include "Sport.h"

Sport::Sport(int id, string name, string model, int hp, int km, int engine, int price, float height) :
	Car(id, name, model, hp, km, engine, price), c_height{ height }
{
	this->c_acceleration = 0;
	this->c_comfort = false;
	this->c_height = height;
}

// getters

int Sport::getAcceleration()
{
	return this->c_acceleration;
}
bool Sport::isComfort()
{
	return this->c_comfort;
}
float Sport::getHeight()
{
	return this->c_height;
}

// setters

void Sport::setAcceleration(int newAcceleration)
{
	this->c_acceleration = newAcceleration;
}

void Sport::setComfort(bool newComfort)
{
	this->c_comfort = newComfort;
}

void Sport::setHeight(float newHeight)
{
	this->c_height = newHeight;
}

void Sport::display(ostream& os) const
{
	os << "Sport ";
	Car::display(os);
	if (this->c_comfort)
	{
		os << " comfortable";
	}
	else
	{
		os << " uncomfortable";
	}
}