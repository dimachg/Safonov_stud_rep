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

// Защита ввода
void wInput(string inf, int& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Пожалуйста, введите "<< inf << endl;
		cin >> n;
	} while (cin.fail());
}

void wInput(string inf, float& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Пожалуйста, введите " << inf << endl;
		cin >> n;
	} while (cin.fail());
}

//void wInput(string inf, string& n) {
//	do {
//		cin.clear();
//		cin.ignore(10000, '\n');
//		cout << "Пожалуйста, введите " << inf << endl;
//		getline(cin, n);
//	} while (cin.fail());
//}



// Трубы
pipe addpipe(int maxid) {
	pipe p;
	p.id = ++maxid;
	wInput("длину",p.lenght);
	wInput("диаметр",p.diameter);
	p.repair = false;
	return p;
}

void outpipe(const pipe& p) {
	cout << "id: " << p.id << endl;
	cout << "Длина трубы: " << p.lenght << endl;
	cout << "Диаметр трубы: " << p.diameter << endl;
	if (p.repair == false) {
		cout << "Труба работает" << endl;
	}
	else {
		cout << "Труба в ремонте" << endl;
	}
}

void editPipe(bool& b) {
	b = !b;
}

// Компрессорные станции
KS addKS(int maxid) {
	KS k;
	k.id = maxid;
	cout << "Пожалуйста, введите имя" << endl;
	cin.ignore();
	getline(cin, k.name);
	wInput("количество цехов", k.amountShops);
	do {
		wInput("количество активных цехов", k.activeShops);
	} while (k.amountShops < k.activeShops || k.activeShops < 0);
	do {
		wInput("эффективность", k.efficiency);
	} while (k.efficiency > 100);
	return(k);
}

void outKS(const KS& k) {
	cout << "id компрессорной станции: " << k.id << endl;
	cout << "Имя компрессорной станции: " << k.name << endl;
	cout << "Количество цехов компрессорной станции: " << k.amountShops << endl;
	cout << "Количество активных цехов компрессорной станции: " << k.activeShops << endl;
	cout << "эффективность компрессорной станции: " << k.efficiency << "%" << endl;
}

void editKS(KS& k) {
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
		cout << "Трубно-компрессорно-станционный интерфейс" << endl;
		cout << "Выберите действие:" << endl;
		cout << "1 - Добавить новую трубу" << endl;
		cout << "2 - Вывести информацию о трубе" << endl;
		cout << "3 - Изменить статус трубы" << endl;
		cout << "4 - Добавить новую компрессорную станцию" << endl;
		cout << "5 - Вывести информацию о компрессорной станции" << endl;
		cout << "6 - Изменение информации о компрессорной станции" << endl;
		cout << "7 - Вывод всех элементов" << endl;
		cout << "8 - Сохранить данные в results.txt" << endl;
		cout << "9 - Загрузить данные из results.txt" << endl;
		cout << "0 - Выход" << endl;

		cout << "Выберите действие:" << endl;
		cin >> choise;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Выберите действие:" << endl;
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
			cout << "Труба:" << endl << endl;
			outpipe(p);
			cout << endl << "Компрессорная станция:" << endl << endl;
			outKS(k);
			break;
		case 8:
			if (maxid != 0) {//проверка наличия трубы (done)
				save(p, k);
			}
			else { cout << "Нет данных для сохранения" << endl; }
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
	else { cout << "Введенно некорректное значение"; }
	}
}