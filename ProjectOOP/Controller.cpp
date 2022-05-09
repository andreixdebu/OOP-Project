#include "Controller.h"

Controller::Controller(CarRepo& repo)
{
	this->c_repo = repo;
}

void Controller::addCar(Car* newCar)
{
	c_repo.addCar(newCar);
	c_undoStack.push(std::make_pair(Action::ADD, newCar));
}

void Controller::removeByID(int id)
{
	Car* C = c_repo.removeCar(id);
	if (C)
		c_undoStack.push(std::make_pair(Action::REMOVE, C));
}

void Controller::undo()
{
	// Undo last operation
	if (!c_undoStack.empty())
	{
		pair<Action, Car*> lastOperation = c_undoStack.top();
		c_redoStack.push(lastOperation); // add the last operation to the redo stack

		if (lastOperation.first == Action::ADD) // if last operation was 'ADD' then remove the added element
			c_repo.removeCar(lastOperation.second->getID());
		else
			c_repo.addCar(lastOperation.second); // if last operation was 'REMOVE' then add the removed element

		c_undoStack.pop();
	}
}

void Controller::redo()
{
	// Redo last operation

	if (!c_redoStack.empty())
	{
		pair<Action, Car*> lastOperation = c_redoStack.top();
		c_undoStack.push(lastOperation); // add the last operation back to the undo stack

		if (lastOperation.first == Action::ADD) // if last operation was 'ADD' then add back the animal
			c_repo.addCar(lastOperation.second);
		else
			c_repo.removeCar(lastOperation.second->getID()); // if last operation was 'REMOVE' then remove back the car

		c_redoStack.pop();
	}
}

void Controller::displayByCheaper(float value)
{
	// Display all the cars that have the price lower than a given value
	c_repo.displayCheaper(std::cout, value, [](Car* C, float val)->bool {
		if (C->getPrice() <= val)
			return true;
		else
			return false;
		});
}

void Controller::displayAll()
{
	// Display all the cars
	c_repo.display(std::cout, [](Car* C)->bool {return true; });
}

void Controller::loadData()
{
	// Loads the data from a csv file
	c_repo.loadData();
}

void Controller::saveData()
{
	// Saves the data from a csv file
	c_repo.saveData();
}