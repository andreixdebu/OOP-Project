#pragma once
#include <istream>
#include "Car.h"
#include <vector>

using namespace std;

class CarRepo
{
private:
	vector<Car*> c_data;

public:
	void addCar(Car*);
	Car* removeCar(int);

	string carToCSV(Car*);

	ostream& display(ostream& os, bool (*filterFunction)(Car*));
	ostream& displayCheaper(ostream& os, float value, bool(*filterFunction2)(Car*, float));

	void loadData();
	void saveData();
};