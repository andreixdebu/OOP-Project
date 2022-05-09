#include "Car.h"

Car::Car(int id, string name, string model, int hp, int km, int engine, int price)
{
	this->c_id = id;
	this->c_name = name;
	this->c_model = model;
	this->c_hp = hp;
	this->c_km = km;
	this->c_engine = engine;
	this->c_price = price;
}

// getters

int Car::getID()
{
	return this->c_id;
}
string Car::getName()
{
	return this->c_name;
}
string Car::getModel()
{
	return this->c_model;
}
int Car::getHP()
{
	return this->c_hp;
}
int Car::getKM()
{
	return this->c_km;
}
int Car::getEngine()
{
	return this->c_engine;
}
int Car::getPrice()
{
	return this->c_price;
}

// setters

void Car::setID(int newID)
{
	this->c_id = newID;
}
void Car::setName(string newName)
{
	this->c_name = newName;
}
void Car::setModel(string modelName)
{
	this->c_model = modelName;
}
void Car::setHP(int newHP)
{
	this->c_hp = newHP;
}
void Car::setKM(int newKM)
{
	this->c_km = newKM;
}
void Car::setEngine(int newEngine)
{
	this->c_engine = newEngine;
}
void Car::setPrice(int newPrice)
{
	this->c_price = newPrice;
}

void Car::display(ostream& os) const
{
	os << "#" << c_id << " " << c_name << " " << c_model << " with " << c_hp << " horsepower, " << c_km << " kilometres, " << c_engine << " engine capacity and costs " << c_price;
}

ostream& operator<<(ostream& os, const Car& c)
{
	c.display(os);
	return os;
}