#pragma once
#include "Car.h"
#include <iostream>
#include <string>

class SUV :
	public Car
{
private:
	float c_height;
	int c_doors;
	bool c_comfort;

public:
	SUV(int id, string name, string model, int hp, int km, int engine, int price, float height, int doors);

	float getHeight();
	int getDoors(); // number of doors
	bool isComfort();

	void setHeight(float);
	void setDoors(int);
	void setComfort(bool);

	void display(ostream& os) const override;
};