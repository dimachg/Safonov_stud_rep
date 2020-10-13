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


// Трубы
pipe addpipe(int maxid) {
	pipe p;
	p.id = maxid;
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
	cin >> k.name;
	do {
		wInput("количество цехов", k.amountShops);
		wInput("количество активных цехов", k.activeShops);
		k.efficiency = (static_cast<float>(k.activeShops) / static_cast<float>(k.amountShops)) * 100;
	} while (k.amountShops < k.activeShops || k.activeShops < 0);
	return(k);
}

void outKS(const KS& k) {
	cout << "id компрессорной станции: " << k.id << endl;
	cout << "Имя компрессорной станции: " << k.name << endl;
	cout << "Количество цехов компрессорной станции: " << k.amountShops << endl;
	cout << "Количество активных цехов компрессорной станции: " << k.activeShops << endl;
	cout << "эффективность компрессорной станции: " << k.efficiency << "%" << endl;
}

void editKS(KS& k, int changeNumber) {
	if (((k.activeShops + changeNumber) > 0) && ((k.activeShops + changeNumber) < k.amountShops)) {
		k.activeShops += changeNumber;
		k.efficiency = (static_cast<float>(k.activeShops) / static_cast<float>(k.amountShops)) * 100;
		cout << "Новая эффективность: " << k.efficiency << "%" << endl;
	}
	else {
		cout << "Превышен предел изменения активных цехов. Изменения не внесены." << endl;
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
		cout << "Трубно-компрессорно-станционный интерфейс" << endl;
		cout << "Выберите действие:" << endl;
		cout << "1 - Добавить новую трубу" << endl;
		cout << "2 - Вывести информацию о трубе" << endl;
		cout << "3 - Изменить статус трубы" << endl;
		cout << "4 - Добавить новую компрессорную станцию" << endl;
		cout << "5 - Вывести информацию о компрессорной станции" << endl;
		cout << "6 - Остановка/Запуск цехов компрессорной станции" << endl;
		cout << "7 - Вывод всех элементов" << endl;
		cout << "8 - Сохранить данные в results.txt" << endl;
		cout << "9 - Загрузить данные из results.txt" << endl;
		cout << "0 - Выход" << endl;
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
			cout << "Количество включаемых цехов (отрицательное значение - количество выключаемых цехов)" << endl;
			cin >> shopChange;
			editKS(k, shopChange);
			break;
		case 7:
			cout << "Труба:" << endl << endl;
			outpipe(p);
			cout << endl << "Компрессорная станция:" << endl << endl;
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