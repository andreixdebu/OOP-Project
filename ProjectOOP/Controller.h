#pragma once
#include "CarRepo.h"
#include <stack>
using namespace std;

enum class Action {
	ADD,
	REMOVE
};
class Controller
{
private:
	CarRepo c_repo;
	std::stack<pair<Action, Car*>> c_undoStack;
	std::stack<pair<Action, Car*>> c_redoStack;
public:
	Controller(CarRepo&);

	void addCar(Car*);
	void removeByID(int);

	void undo();
	void redo();

	void displayByCheaper(float);
	void displayAll();

	void loadData();
	void saveData();

};