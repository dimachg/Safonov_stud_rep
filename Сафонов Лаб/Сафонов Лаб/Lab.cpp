#include <iostream>
#include <fstream>
#include <string>

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


// �����
pipe addpipe(int maxid) {
	pipe p;
	p.id = maxid;
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
	cin >> k.name;
	do {
		wInput("���������� �����", k.amountShops);
		wInput("���������� �������� �����", k.activeShops);
		k.efficiency = (static_cast<float>(k.activeShops) / static_cast<float>(k.amountShops)) * 100;
	} while (k.amountShops < k.activeShops || k.activeShops < 0);
	return(k);
}

void outKS(const KS& k) {
	cout << "id ������������� �������: " << k.id << endl;
	cout << "��� ������������� �������: " << k.name << endl;
	cout << "���������� ����� ������������� �������: " << k.amountShops << endl;
	cout << "���������� �������� ����� ������������� �������: " << k.activeShops << endl;
	cout << "������������� ������������� �������: " << k.efficiency << "%" << endl;
}

void editKS(KS& k, int changeNumber) {
	if (((k.activeShops + changeNumber) > 0) && ((k.activeShops + changeNumber) < k.amountShops)) {
		k.activeShops += changeNumber;
		k.efficiency = (static_cast<float>(k.activeShops) / static_cast<float>(k.amountShops)) * 100;
		cout << "����� �������������: " << k.efficiency << "%" << endl;
	}
	else {
		cout << "�������� ������ ��������� �������� �����. ��������� �� �������." << endl;
	}
}

void save(pipe p, KS k) 
{
	ofstream fout;
	fout.open("results.txt", ios::out);
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

void load(pipe& p, KS& k) 
{
	ifstream fin;
	fin.open("results.txt", ios::in);
	fin >> p.id;
	fin >> p.lenght;
	fin >> p.diameter;
	fin >> p.repair;
	fin >> k.id;
	fin >> k.name;
	fin >> k.amountShops;
	fin >> k.activeShops;
	fin >> k.efficiency;
}

int main() {
	setlocale(LC_ALL, "ru");
	int chs;
	int shopChange;
	pipe p;
	KS k;
	while (true) {
		cout << endl;
		cout << "������-������������-����������� ���������" << endl;
		cout << "�������� ��������:" << endl;
		cout << "1 - �������� ����� �����" << endl;
		cout << "2 - ������� ���������� � �����" << endl;
		cout << "3 - �������� ������ �����" << endl;
		cout << "4 - �������� ����� ������������� �������" << endl;
		cout << "5 - ������� ���������� � ������������� �������" << endl;
		cout << "6 - ���������/������ ����� ������������� �������" << endl;
		cout << "7 - ����� ���� ���������" << endl;
		cout << "8 - ��������� ������ � results.txt" << endl;
		cout << "9 - ��������� ������ �� results.txt" << endl;
		cout << "0 - �����" << endl;
	cin >> chs;
		switch (chs)
		{
		case 1:
			p = addpipe(1);
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
			cout << "���������� ���������� ����� (������������� �������� - ���������� ����������� �����)" << endl;
			cin >> shopChange;
			editKS(k, shopChange);
			break;
		case 7:
			cout << "�����:" << endl << endl;
			outpipe(p);
			cout << endl << "������������� �������:" << endl << endl;
			outKS(k);
			break;
		case 8:
			save(p,k);
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
}