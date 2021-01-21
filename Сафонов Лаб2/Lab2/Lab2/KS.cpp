#include "utils.h"
#include "KS.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void KS::addKS(vector<KS>& kslist, KS k, int& maxid2)
{
	k.id = maxid2;
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
	kslist.push_back(k);
	maxid2++;
}

void KS::deleteKS(vector<KS>& kslist)
{
	int i = 0;
	wInput("номер удаляемой компрессорной станции", i);
	kslist[i].amountShops = 0;
}

void KS::outKS(vector<KS> kslist)
{
	for (int i = 0; i <= (kslist.size() - 1); i++) {
		if (kslist[i].amountShops != 0) {
			cout << "id компрессорной станции: " << kslist[i].id << endl;
			cout << "Имя компрессорной станции: " << kslist[i].name << endl;
			cout << "Количество цехов компрессорной станции: " << kslist[i].amountShops << endl;
			cout << "Количество активных цехов компрессорной станции: " << kslist[i].activeShops << endl;
			cout << "эффективность компрессорной станции: " << kslist[i].efficiency << "%" << endl;
		}
	}
}

void KS::editKS(vector<KS>& kslist, int i)
{
	wInput("номер изменяемой компрессорной станции", i);
	int shopChange;
	int newEfficiency;
	do {
		wInput("количество включаемых цехов (отрицательное значение - количество выключаемых цехов)", shopChange);
	} while (((kslist[i].activeShops + shopChange) < 0) || ((kslist[i].activeShops + shopChange) > kslist[i].amountShops));
	kslist[i].activeShops = kslist[i].activeShops + shopChange;
	do {
		wInput("новую эффективность", newEfficiency);
	} while ((newEfficiency < 0) || (newEfficiency > 100));
	kslist[i].efficiency = newEfficiency;
}

void KS::findKS(vector<KS> KSlist, vector<KS>& findedKS)
{
	findedKS.clear();
	string name;
	float inactive = 101;
	cout << "Введите фильтр по имени или 0 для отсутствия фильтра" << endl;
	cin.ignore();
	getline(cin, name);
	wInput("фильтр по проценту незадействованных цехов или 101 для отсутсвия фильтра", inactive);
	int sz = KSlist.size();
	if (inactive != 101) {
		for (int i = 0; i < sz; i++) {
			if ((KSlist[i].amountShops - KSlist[i].activeShops) / KSlist[i].amountShops == inactive) {
				findedKS.push_back(KSlist[i]);
			}
		}
	}

	if (name != "0") {
		for (int i = 0; i < sz; i++) {
			if (KSlist[i].name == name) {
				findedKS.push_back(KSlist[i]);
			}
		}
	}

	if (name == "0" && inactive == 101) {
		for (int i = 0; i < sz; i++) {
			findedKS.push_back(KSlist[i]);
		}
	}
}

void KS::KSid(vector<KS> KSlist, vector<KS> findedKS)
{
	findedKS.clear();
	int n = 0;
	int id = 0;
	wInput("количество редактируемых КС", n);
	for (int i = 0; i < n; i++) {
		string stri = to_string(i + 1);
		wInput("id " + stri + " КС", id);
		findedKS.push_back(KSlist[id]);
	}
}

void KS::KSPackEdit(vector<KS>& KSlist, vector<KS>& findedKS)
{
	int sz = findedKS.size();
	int shopChange;
	int newEfficiency;
	bool check = 1;

	do {
		wInput("количество включаемых цехов (отрицательное значение - количество выключаемых цехов)", shopChange);
		wInput("новую эффективность", newEfficiency);
		check = 1;
		for (int i = 1; i < sz; i++) {
			if (((findedKS[i].activeShops + shopChange) < 0) || ((findedKS[i].activeShops + shopChange) > findedKS[i].amountShops) || newEfficiency < 0 || newEfficiency > 100) {
				check = 0;
			}
			findedKS[i].activeShops = findedKS[i].activeShops + shopChange;
			findedKS[i].efficiency = newEfficiency;
		}
	} while (check = 0);
}

void KS::loadKS(vector<KS>& KSlist)
{
	ifstream fin;
	fin.open("KS.txt", ios::in);
	if (fin.is_open()) {
		int sz2;
		fin >> sz2;
		for (int i = 0; i < sz2; i++) {
			KS k;
			KSlist.push_back(k);
			fin >> KSlist[i].id;
			fin >> KSlist[i].name;
			fin >> KSlist[i].amountShops;
			fin >> KSlist[i].activeShops;
			fin >> KSlist[i].efficiency;
		}
	}
	fin.close();
}
