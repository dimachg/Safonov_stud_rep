#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct pipe {
	int id;
	float lenght;
	int diameter;
	bool repair;
};

struct KS {
	int id;
	string name;
	int amountShops;
	int activeShops;
	float efficiency;
};

// ������ �����
void wInput(string inf, int& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "����������, ������� "<< inf << endl;
		cin >> n;
	} while (cin.fail());
}

void wInput(string inf, float& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "����������, ������� " << inf << endl;
		cin >> n;
	} while (cin.fail());
}

//void wInput(string inf, string& n) {
//	do {
//		cin.clear();
//		cin.ignore(10000, '\n');
//		cout << "����������, ������� " << inf << endl;
//		getline(cin, n);
//	} while (cin.fail());
//}



// �����
pipe addpipe(int maxid) {
	pipe p;
	p.id = ++maxid;
	wInput("�����",p.lenght);
	wInput("�������",p.diameter);
	p.repair = false;
	return p;
}

void outpipe(const pipe& p) {
	cout << "id: " << p.id << endl;
	cout << "����� �����: " << p.lenght << endl;
	cout << "������� �����: " << p.diameter << endl;
	if (p.repair == false) {
		cout << "����� ��������" << endl;
	}
	else {
		cout << "����� � �������" << endl;
	}
}

void editPipe(bool& b) {
	b = !b;
}

// ������������� �������
KS addKS(int maxid) {
	KS k;
	k.id = maxid;
	cout << "����������, ������� ���" << endl;
	cin.ignore();
	getline(cin, k.name);
	wInput("���������� �����", k.amountShops);
	do {
		wInput("���������� �������� �����", k.activeShops);
	} while (k.amountShops < k.activeShops || k.activeShops < 0);
	do {
		wInput("�������������", k.efficiency);
	} while (k.efficiency > 100);
	return(k);
}

void outKS(const KS& k) {
	cout << "id ������������� �������: " << k.id << endl;
	cout << "��� ������������� �������: " << k.name << endl;
	cout << "���������� ����� ������������� �������: " << k.amountShops << endl;
	cout << "���������� �������� ����� ������������� �������: " << k.activeShops << endl;
	cout << "������������� ������������� �������: " << k.efficiency << "%" << endl;
}

void editKS(KS& k) {
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

void save(pipe p, KS k) 
{
	ofstream fout;
	fout.open("results.txt", ios::out);
	if (fout.is_open()) {
		fout << p.id << endl;
		fout << p.lenght << endl;
		fout << p.diameter << endl;
		fout << p.repair << endl;

		fout << k.id << endl;
		fout << k.name << endl;
		fout << k.amountShops << endl;
		fout << k.activeShops << endl;
		fout << k.efficiency;
		fout.close();
	}
}

void load(pipe& p, KS& k) 
{
	ifstream fin;
	fin.open("results.txt", ios::in);
	if (fin.is_open()) {
		fin >> p.id;
		fin >> p.lenght;
		fin >> p.diameter;
		fin >> p.repair;
		fin >> k.id;
		fin >> k.name;
		fin >> k.amountShops;
		fin >> k.activeShops;
		fin >> k.efficiency;
		fin.close();
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //https://nicknixer.ru/programmirovanie/russkie-simvolybukvy-pri-vvodevyvode-v-konsol-na-c/
	int choise;
	pipe p;
	KS k;
	int maxid = 0;

	while (true) {
		cout << endl;
		cout << "������-������������-����������� ���������" << endl;
		cout << "�������� ��������:" << endl;
		cout << "1 - �������� ����� �����" << endl;
		cout << "2 - ������� ���������� � �����" << endl;
		cout << "3 - �������� ������ �����" << endl;
		cout << "4 - �������� ����� ������������� �������" << endl;
		cout << "5 - ������� ���������� � ������������� �������" << endl;
		cout << "6 - ��������� ���������� � ������������� �������" << endl;
		cout << "7 - ����� ���� ���������" << endl;
		cout << "8 - ��������� ������ � results.txt" << endl;
		cout << "9 - ��������� ������ �� results.txt" << endl;
		cout << "0 - �����" << endl;

		cout << "�������� ��������:" << endl;
		cin >> choise;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "�������� ��������:" << endl;
			cin >> choise;
		}
		
	if (choise == 1 || choise == 2 || choise == 3 || choise == 4 || choise == 5 || choise == 6 || choise == 7 || choise == 8 || choise == 9 || choise == 0) {
		switch (choise)
		{
		case 1:
			p = addpipe(maxid);
			maxid++;
			break;
		case 2:
			outpipe(p);
			break;
		case 3:
			editPipe(p.repair);
			break;
		case 4:
			k = addKS(1);
			break;
		case 5:
			outKS(k);
			break;
		case 6:
			editKS(k);
			break;
		case 7:
			cout << "�����:" << endl << endl;
			outpipe(p);
			cout << endl << "������������� �������:" << endl << endl;
			outKS(k);
			break;
		case 8:
			if (maxid != 0) {//�������� ������� ����� (done)
				save(p, k);
			}
			else { cout << "��� ������ ��� ����������" << endl; }
			break;
		case 9:
			load(p, k);
			break;
		case 0:
			return 0;
			break;
		default:
			return 0;
			break;
		}
	}
	else { cout << "�������� ������������ ��������"; }
	}
}