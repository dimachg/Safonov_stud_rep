#include "utils.h"
#include "KS.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void KS::addKS(vector<KS>& kslist, KS k, int& maxid2)
{
	k.id = maxid2;
	cout << "����������, ������� ���" << endl;
	cin.ignore();
	getline(cin, k.name);	//��������� �������� (+)
	wInput("���������� �����", k.amountShops);
	do {
		wInput("���������� �������� �����", k.activeShops);
	} while (k.amountShops < k.activeShops || k.activeShops < 0);	//�������� ����������� ����� (+)
	do {
		wInput("�������������", k.efficiency);
	} while (k.efficiency > 100);	//������������� �� ����� (+)
	kslist.push_back(k);
	maxid2++;
}

void KS::deleteKS(vector<KS>& kslist)
{
	int i = 0;
	wInput("����� ��������� ������������� �������", i);
	kslist[i].amountShops = 0;
}

void KS::outKS(vector<KS> kslist)
{
	for (int i = 0; i <= (kslist.size() - 1); i++) {
		if (kslist[i].amountShops != 0) {
			cout << "id ������������� �������: " << kslist[i].id << endl;
			cout << "��� ������������� �������: " << kslist[i].name << endl;
			cout << "���������� ����� ������������� �������: " << kslist[i].amountShops << endl;
			cout << "���������� �������� ����� ������������� �������: " << kslist[i].activeShops << endl;
			cout << "������������� ������������� �������: " << kslist[i].efficiency << "%" << endl;
		}
	}
}

void KS::editKS(vector<KS>& kslist, int i)
{
	wInput("����� ���������� ������������� �������", i);
	int shopChange;
	int newEfficiency;
	do {
		wInput("���������� ���������� ����� (������������� �������� - ���������� ����������� �����)", shopChange);
	} while (((kslist[i].activeShops + shopChange) < 0) || ((kslist[i].activeShops + shopChange) > kslist[i].amountShops));
	kslist[i].activeShops = kslist[i].activeShops + shopChange;
	do {
		wInput("����� �������������", newEfficiency);
	} while ((newEfficiency < 0) || (newEfficiency > 100));
	kslist[i].efficiency = newEfficiency;
}

void KS::findKS(vector<KS> KSlist, vector<KS>& findedKS)
{
	findedKS.clear();
	string name;
	float inactive = 101;
	cout << "������� ������ �� ����� ��� 0 ��� ���������� �������" << endl;
	cin.ignore();
	getline(cin, name);
	wInput("������ �� �������� ����������������� ����� ��� 101 ��� ��������� �������", inactive);
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
	wInput("���������� ������������� ��", n);
	for (int i = 0; i < n; i++) {
		string stri = to_string(i + 1);
		wInput("id " + stri + " ��", id);
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
		wInput("���������� ���������� ����� (������������� �������� - ���������� ����������� �����)", shopChange);
		wInput("����� �������������", newEfficiency);
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
