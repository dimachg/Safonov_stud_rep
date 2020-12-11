#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Pipe.h"
#include "KS.h"
#include "utility.h"

using namespace std;



//void wInput(string inf, string& n) {
//	do {
//		cin.clear();
//		cin.ignore(10000, '\n');
//		cout << "Пожалуйста, введите " << inf << endl;
//		getline(cin, n);
//	} while (cin.fail());
//}

void save(Pipe p, KS k) 
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

void load(Pipe& p, KS& k) {
	ifstream fin;
	fin.open("results.txt", ios::in);
	if (fin.is_open()) {	//проверка факта открытия файла (+)
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
	int maxid = 0;
	Pipe p;
	KS k;

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
		/*int checkSwitch = 0;
		int i = 0;
		for (i = 0; i < 9; i++) {
			if (choise == i) {
				checkSwitch = 1;
			}
		}
		*/
		//проверка ввода только 1..0 (+)
		if (choise == 1 || choise == 2 || choise == 3 || choise == 4 || choise == 5 || choise == 6 || choise == 7 || choise == 8 || choise == 9 || choise == 0) {
		switch (choise)
		{
		case 1:
			Pipe p;
			Pipe.addpipe(p, maxid);
			maxid++;
			break;
		case 2:
			Pipe.outpipe(p);
			break;
		case 3:
			Pipe.editPipe(p.repair);
			break;
		case 4:
			KS k;
			k = KS.addKS(k, maxid);
			break;
		case 5:
			KS.outKS(k);
			break;
		case 6:
			KS.editKS(k);
			break;
		case 7:
			cout << "Труба:" << endl << endl;
			Pipe.outpipe(p);
			cout << endl << "Компрессорная станция:" << endl << endl;
			KS.outKS(k);
			break;
		case 8:
			if (maxid != 0) {//проверка наличия трубы (+)
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
	else { cout << "Введенно некорректное значение";  }
	}
}