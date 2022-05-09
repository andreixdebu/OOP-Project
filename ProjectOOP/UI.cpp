#include "UI.h"
#include <iostream>
#include <string>
#include "Car.h"
#include "logic.cpp"

using namespace std;

UI::UI(Controller& C) : c_controller{ C }
{

}

void UI::add()
{
	// Asks the user for input. Creates Car object and adds it to the repository

	int id, hp, km, engine, price;
	string name, model;
	cout << "id: " << endl;
	id = intValidation();
	cout << "name: " << endl;
	cin >> name;
	cout << "model: " << endl;
	cin >> model;
	cout << "hp: " << endl;
	hp = intValidation();
	cout << "km: " << endl;
	km = intValidation();
	cout << "engine: " << endl;
	engine = intValidation();
	cout << "price: " << endl;
	price = intValidation();

	Car* newCar = new Car(id, name, model, hp, km, engine, price);
	c_controller.addCar(newCar);
}

void UI::remove()
{
	// Asks the user for input. Removes Car with the given id
	int id;
	cout << "Car ID to be removed: ";
	id = intValidation();
	c_controller.removeByID(id);
}

void UI::Menu()
{
	// Start Menu

	c_controller.loadData(); // Loads the data from the csv file 'Input.csv'
	char op;
	while (true)
	{
		cout << "Please insert your option: " << endl;
		cout << "\t 1 - Add" << endl;
		cout << "\t 2 - Remove" << endl;
		cout << "\t 3 - Display all" << endl;
		cout << "\t 4 - Display cars with price lower than value" << endl;
		cout << "\t 5 - Undo" << endl;
		cout << "\t 6 - Redo" << endl;
		cout << "\t 0 - Exit" << endl;

		cin >> op;
		if (op == '1')
			add();
		else if (op == '2')
			remove();
		else if (op == '3')
			c_controller.displayAll();
		else if (op == '4')
		{
			float value = floatValidation();
			c_controller.displayByCheaper(value);
		}
		else if (op == '5')
			c_controller.undo();
		else if (op == '6')
			c_controller.redo();
		else if (op == '0')
			break;
		else
			cout << "Invalid option!" << endl;
	}
	c_controller.saveData(); // Saves the data from the repository into the csv file 'Output.csv'
}