#include "Sedan.h"

Sedan::Sedan(int id, string name, string model, int hp, int km, int engine, int price, Types type) :
	Car(id, name, model, hp, km, engine, price), c_type{ type }
{
	this->c_acceleration = 0;
	this->c_comfort = false;
	this->c_type = type;
}

// getters

int Sedan::getAcceleration()
{
	return this->c_acceleration;
}

bool Sedan::isComfort()
{
	return this->c_comfort;
}

Types Sedan::getType()
{
	return this->c_type;
}

// setters

void Sedan::setAcceleration(int newAcceleration)
{
	this->c_acceleration = newAcceleration;
}

void Sedan::setComfort(bool newComfort)
{
	this->c_comfort = newComfort;
}

void Sedan::setType(Types newType)
{
	this->c_type = newType;
}

void Sedan::display(ostream& os) const
{
	os << "Sedan ";
	Car::display(os);
	if (this->c_comfort == true)
	{
		os << " comfortable";
	}
	else
	{
		os << " uncomfortable";
	}
}