#include <iostream>
#include "utility.h"

void wInput(string inf, int& n)
{
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Пожалуйста, введите " << inf << endl;
		cin >> n;
	} while (cin.fail());
}

void wInput(string inf, float& n)
{
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Пожалуйста, введите " << inf << endl;
		cin >> n;
	} while (cin.fail());
}
