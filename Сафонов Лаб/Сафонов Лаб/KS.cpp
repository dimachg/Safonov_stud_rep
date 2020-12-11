#include<iostream>
#include "KS.h"
#include "utility.h"

using namespace std;

void KS::addKS(KS k, int maxid)
{
	k.id = ++maxid;
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
}

void KS::outKS(const KS& k)
{
	cout << "id ������������� �������: " << k.id << endl;
	cout << "��� ������������� �������: " << k.name << endl;
	cout << "���������� ����� ������������� �������: " << k.amountShops << endl;
	cout << "���������� �������� ����� ������������� �������: " << k.activeShops << endl;
	cout << "������������� ������������� �������: " << k.efficiency << "%" << endl;
}

void KS::editKS(KS& k)
{
	int shopChange;
	int newEfficiency;
	do {	//��������� �������� �����
		cout << "������� ���������� ���������� ����� (������������� �������� - ���������� ����������� �����)" << endl;
		cin >> shopChange;
	} while (((k.activeShops + shopChange) < 0) || ((k.activeShops + shopChange) > k.amountShops));
	k.activeShops = k.activeShops + shopChange;
	do {	//��������� �������������
		cout << "������� ����� �������������" << endl;
		cin >> newEfficiency;
	} while ((newEfficiency < 0) || (newEfficiency > 100));
	k.efficiency = newEfficiency;
}
