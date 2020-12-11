#include<iostream>
#include "KS.h"
#include "utility.h"

using namespace std;

void KS::addKS(KS k, int maxid)
{
	k.id = ++maxid;
	cout << "Пожалуйста, введите имя" << endl;
	cin.ignore();
	getline(cin, k.name);	//поддержка пробелов (+)
	wInput("количество цехов", k.amountShops);
	do {
		wInput("количество активных цехов", k.activeShops);
	} while (k.amountShops < k.activeShops || k.activeShops < 0);	//проверка корректного ввода (+)
	do {
		wInput("эффективность", k.efficiency);
	} while (k.efficiency > 100);	//эффективность по вводу (+)
}

void KS::outKS(const KS& k)
{
	cout << "id компрессорной станции: " << k.id << endl;
	cout << "Имя компрессорной станции: " << k.name << endl;
	cout << "Количество цехов компрессорной станции: " << k.amountShops << endl;
	cout << "Количество активных цехов компрессорной станции: " << k.activeShops << endl;
	cout << "эффективность компрессорной станции: " << k.efficiency << "%" << endl;
}

void KS::editKS(KS& k)
{
	int shopChange;
	int newEfficiency;
	do {	//изменение активных цехов
		cout << "Введите количество включаемых цехов (отрицательное значение - количество выключаемых цехов)" << endl;
		cin >> shopChange;
	} while (((k.activeShops + shopChange) < 0) || ((k.activeShops + shopChange) > k.amountShops));
	k.activeShops = k.activeShops + shopChange;
	do {	//изменение эффективности
		cout << "Введите новую эффективность" << endl;
		cin >> newEfficiency;
	} while ((newEfficiency < 0) || (newEfficiency > 100));
	k.efficiency = newEfficiency;
}
