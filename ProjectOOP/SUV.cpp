#include "SUV.h"

SUV::SUV(int id, string name, string model, int hp, int km, int engine, int price, float height, int doors) :
	Car(id, name, model, hp, km, engine, price), c_height{ height }, c_doors{ doors }
{
	this->c_height = height;
	this->c_doors = 5;
	this->c_comfort = false;
}

// getters

float SUV::getHeight()
{
	return this->c_height;
}
int SUV::getDoors()
{
	return this->c_doors;
}
bool SUV::isComfort()
{
	return this->c_comfort;
}

// setters

void SUV::setHeight(float newHeight)
{
	this->c_height = newHeight;
}
void SUV::setDoors(int newDoors)
{
	this->c_doors = newDoors;
}
void SUV::setComfort(bool newComfort)
{
	this->c_comfort = newComfort;
}

void SUV::display(ostream& os) const
{
	os << "SUV ";
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