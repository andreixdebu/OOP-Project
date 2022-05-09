#pragma once
#include "Controller.h"

class UI
{
private:
	Controller c_controller;

public:
	UI(Controller&);

	void add();
	void remove();

	void Menu();


};