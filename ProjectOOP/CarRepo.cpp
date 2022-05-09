#include "CarRepo.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void CarRepo::addCar(Car* newCar)
{
	// Adds a car to the repository
	c_data.push_back(newCar);
}

Car* CarRepo::removeCar(int id)
{
	// Removes the car by ID, returns the removed car for the undo/redo
	Car* result = nullptr;
	auto index = find_if(c_data.begin(), c_data.end(), [id](Car* result)->bool {
		return result->getID() == id;
		});
	if (index != c_data.end()) {
		result = *index;
		c_data.erase(index);
	}
	return result;
}

string CarRepo::carToCSV(Car* C)
{
	// Returns a csv representation of a car 'C'
	string result;
	result = to_string(C->getID()) + ',' + C->getName() + ',' + C->getModel();
	result += ',' + to_string(C->getHP()) + ',' + to_string(C->getKM()) + ',' + to_string(C->getEngine()) + ',' + to_string(C->getPrice());
	return result;
}

ostream& CarRepo::display(ostream& os, bool(*filterFunction)(Car*))
{
	// Displays all the cars that satisfy a given property 'filterFunction'
	for (auto i = 0; i < c_data.size(); i++)
		if (filterFunction(c_data[i]) == true)
			os << *c_data[i] << endl;
	return os;
}

ostream& CarRepo::displayCheaper(ostream& os, float value, bool(*filterFunction2)(Car*, float))
{
	// Displays all the cars that satisfy a given property 'filterFunction2'
	for (auto i = 0; i < c_data.size(); i++)
		if (filterFunction2(c_data[i], value) == true)
			os << *c_data[i] << endl;
	return os;
}

void CarRepo::loadData()
{
	// Reads the data from 'Input.csv' and loads it into the repository
	fstream inputFile;
	try
	{
		inputFile.open("Input.csv", ios::in);
	}
	catch (const exception&)
	{
		cout << "\n Input file could not be opened \n";
	}
	string line;

	while (getline(inputFile, line))
	{
		vector<string> tokens; // list of the CSVs
		stringstream ss(line);
		string token;
		while (getline(ss, token, ',')) // split and place each token into the list of tokens
			tokens.push_back(token);

		// store the data from tokens to variables
		int id = (stoi(tokens[0])); // stoi(string) -> returns the int representation of the string
		string name = (tokens[1]);
		string model = (tokens[2]);
		int hp = (stof(tokens[3]));
		int km = (stof(tokens[4]));
		int engine = (stof(tokens[5]));
		int price = (stof(tokens[6]));

		// Create and add a car
		Car* newCar = new Car(id, name, model, hp, km, engine, price);
		addCar(newCar);
	}
	inputFile.close();
}

void CarRepo::saveData()
{
	// Writes and saves the data from the repository to 'Output.csv'
	fstream fout;
	try
	{
		fout.open("Output.csv", ios::out);
	}
	catch (const exception&)
	{
		cout << "\n Output file could not be opened \n";
	}

	for (auto i = 0; i < c_data.size(); i++) // print every car
		fout << carToCSV(c_data[i]) << endl;
	fout.close();
}