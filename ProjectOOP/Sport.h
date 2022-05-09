#pragma once
#include "Car.h"

class Sport :
	public Car
{
private:
	int c_acceleration;
	bool c_comfort;
	float c_height;

public:
	Sport(int id, string name, string model, int hp, int km, int engine, int price, float height);

	int getAcceleration();
	bool isComfort();
	float getHeight();

	void setAcceleration(int); // 100 km/h in seconds
	void setComfort(bool);
	void setHeight(float); // in cm

	void display(ostream& os) const override;
};