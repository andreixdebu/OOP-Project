#pragma once
#include "Car.h"
#include <iostream>

enum class Types { // note: friend ostream& operator <<
	LUXURY,
	AGGRESSIVE,
};

class Sedan :
	public Car
{
private:
	int c_acceleration;
	bool c_comfort;
	Types c_type;

public:
	Sedan(int id, string name, string model, int hp, int km, int engine, int price, Types type);

	int getAcceleration();
	bool isComfort();
	Types getType();

	void setAcceleration(int);
	void setComfort(bool);
	void setType(Types);

	void display(ostream& os) const override;
};