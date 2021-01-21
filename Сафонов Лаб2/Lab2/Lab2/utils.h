#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>

void wInput(string inf, T& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Пожалуйста, введите " << inf << endl;
		cin >> n;
	} while (cin.fail());
}

template <typename T>
void swapValues(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
T tryInput(std::string alert, T min, T max = 1000000)
{
	T x;
	std::cout << alert;
	while ((std::cin >> x).fail() || x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << alert;
	}
	return x;
}

template <typename T>
int tryInput(std::string alert, const std::unordered_map <int, T>& myMap)
{
	if (!myMap.empty())
	{
		int x;
		std::cout << alert;
		while ((std::cin >> x).fail() || myMap.find(x) == myMap.end())
		{
			if (x == 0)
				return 0;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << alert;
		}
		return x;
	}
	else
	{
		return 0;
	}
}