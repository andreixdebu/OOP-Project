#include <iostream>
#include <string>
#include "Car.h"
#include "Sedan.h"
#include "Sport.h"
#include "SUV.h"
#include "CarRepo.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"
using namespace std;

int main()
{
	TestAll();
	CarRepo repo;
	Controller C(repo);
	UI ui(C);

	ui.Menu();
}