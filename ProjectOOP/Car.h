#pragma once
#include <string>
#include <iostream>

using namespace std;

class Car
{
private:
	int c_id;
protected:
	string c_name;
	string c_model;
	int c_hp; // number of horsepower of the car
	int c_km;
	int c_engine; // size of the engine
	int c_price; // number of doors

public:
	Car(int id, string name, string model, int hp, int km, int engine, int price);

	int getID(); // getters
	string getName();
	string getModel();
	int getHP();
	int getKM();
	int getEngine();
	int getPrice();

	void setID(int); // setters
	void setName(string);
	void setModel(string modelName);
	void setHP(int);
	void setKM(int);
	void setEngine(int);
	void setPrice(int);

	virtual void display(ostream& os) const;
	friend ostream& operator <<(ostream& os, const Car& c);

};