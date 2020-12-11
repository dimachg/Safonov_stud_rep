#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>


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

void wInput(string inf, int& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "ожалуйста, введите " << inf << endl;
		cin >> n;
	} while (cin.fail());
}

void wInput(string inf, float& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "ожалуйста, введите " << inf << endl;
		cin >> n;
	} while (cin.fail());
}

//void wInput(string inf, string& n) {
//	do {
//		cin.clear();
//		cin.ignore(10000, '\n');
//		cout << "Ïîæàëóéñòà, ââåäèòå " << inf << endl;
//		getline(cin, n);
//	} while (cin.fail());
//}



void addpipe(vector <pipe>& pipelist, pipe p, int& maxid) {
	p.id = maxid;
	wInput("длину", p.lenght);
	wInput("диаметр", p.diameter);
	p.repair = false;
	pipelist.push_back(p);
	maxid++;
}

void deletepipe(vector <pipe>& pipelist) {
	int i;
	wInput("номер удаляемого элемента", i);
	pipelist[i].lenght = 0; //сделать нормльное удаление, а не вот это вот "сокрытие фактов"
}

void outpipe(vector <pipe> pipelist) {
	int i = 0;
	for (i = 0; i <= (pipelist.size()-1); i++)
	{
		if (pipelist[i].lenght != 0 && pipelist[i].diameter != 0) {
			cout << "id: " << pipelist[i].id << endl;
			cout << "Длина трубы: " << pipelist[i].lenght << endl;
			cout << "Диаметр трубы: " << pipelist[i].diameter << endl;
			if (pipelist[i].repair == false) {
				cout << "Труба работает" << endl;
			}
			else {
				cout << "Труба в ремонте" << endl;
			}
		}
		
	}

}

void editPipe(vector <pipe>& pipelist) {
	int i;
	wInput("номер изменяемой трубы", i);
	pipelist[i].repair = !pipelist[i].repair;
}

void addKS(vector <KS>& kslist, KS k, int& maxid2) {
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

void deleteKS(vector <KS>& kslist) {
	int i = 0;
	wInput("номер удаляемой компрессорной станции", i);
	kslist[i].amountShops = 0; //сделать нормльное удаление, а не вот это вот "сокрытие фактов"
}

void outKS(vector <KS> kslist) {
	int i = 0;
	for (i = 1; i <= (kslist.size()-1); i++) {
		if (kslist[i].amountShops != 0) {
			cout << "id компрессорной станции: " << kslist[i].id << endl;
			cout << "Имя компрессорной станции: " << kslist[i].name << endl;
			cout << "Количество цехов компрессорной станции: " << kslist[i].amountShops << endl;
			cout << "Количество активных цехов компрессорной станции: " << kslist[i].activeShops << endl;
			cout << "эффективность компрессорной станции: " << kslist[i].efficiency << "%" << endl;
		}
	}
	
}

void editKS(vector <KS>& kslist, int i) {
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
	vector <pipe> pipelist;
	pipelist.resize(1);
	vector <KS> kslist;
	kslist.resize(1);
	vector <KS> KSlist;
	int maxid = 1;
	int maxid2 = 1;
	int i = 0;

	p.id = 0; //пустая инициализация
	p.lenght = 0;
	p.diameter = 0;
	k.id = 0;
	k.name = "0";
	k.amountShops = 0;
	k.activeShops = 0;

	while (true) {
		cout << endl;
		cout << "Трубно-компрессорно-станционный интерфейс" << endl;
		cout << "Выберите действие:" << endl;
		cout << "1 - Добавить новую трубу" << endl;
		cout << "2 - Удалить трубу" << endl;
		cout << "3 - Изменить статус трубы" << endl;
		cout << "4 - Добавить новую компрессорную станцию" << endl;
		cout << "5 - Изменение информации о компрессорной станции" << endl;
		cout << "6 - Удалить компрессорную станцию" << endl;
		cout << "7 - Вывод всех элементов" << endl;
		cout << "8 - Сохранить данные в results.txt" << endl;
		cout << "9 - Загрузить данные из results.txt" << endl;
		cout << "10 - Поиск объектов по фильтру" << endl;
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
		if (choise == 1 || choise == 2 || choise == 3 || choise == 4 || choise == 5 || choise == 6 || choise == 7 || choise == 8 || choise == 9 || choise == 0) {
			switch (choise)
			{
			case 1:
				addpipe(pipelist, p, maxid);
				break;
			case 2:
				deletepipe(pipelist);
				break;
			case 3:
				editPipe(pipelist);
				break;
			case 4:
				addKS(kslist, k, maxid2);
				break;
			case 5:
				editKS(kslist, i);
				break;
			case 6:
				deleteKS(kslist);
				break;
			case 7:
				cout << "Трубы: " << endl << endl;
				outpipe(pipelist);
				cout << endl << "Компрессорная станция:" << endl << endl;
				outKS(kslist);
				break;
			case 8:
				if (maxid != 0) {
					save(p, k);
				}
				else { cout << "Нет данных для сохранения" << endl; }
				break;
			case 9:
				load(p, k);
				break;
			case 10:
				//тут остановился. Сделать поиск по фильтрам. Скорее всего все в одной функции. Или деление на поиск трубы и поиск КС
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