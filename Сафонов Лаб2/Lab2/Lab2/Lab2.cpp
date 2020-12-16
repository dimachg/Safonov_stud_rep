#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>


using namespace std;

struct pipe {
	int id;
	string name;
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
cout << "Пожалуйста, введите " << inf << endl;
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


//Трубы
void addpipe(vector <pipe>& pipelist, pipe p, int& maxid) {
	p.id = maxid;
	cout << "Пожалуйста, введите имя" << endl;
	cin.ignore();
	getline(cin, p.name);
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
	for (i = 0; i <= (pipelist.size() - 1); i++)
	{
		if (pipelist[i].lenght != 0 && pipelist[i].diameter != 0) {
			cout << "id: " << pipelist[i].id << endl;
			cout << "Имя: " << pipelist[i].name << endl;
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

void findPipe(vector <pipe> pipelist, vector <pipe>& findedPipes) {
	findedPipes.clear();
	string name;
	int repair;
	cout << "Введите фильтр по имени или 0 для отсутствия фильтра" << endl;
	cin.ignore();
	getline(cin, name);
	wInput("фильтр по статусу работы 1-вкл 0-в ремонте 2-отсутсвие фильтра", repair);
	bool r = 1;
	int sz = pipelist.size();
	if (repair == 1) { r = 1; }
	if (repair == 0) { r = 0; }
	if (repair != 2) {
		for (int i = 0; i < sz; i++) {
			if (pipelist[i].repair == r) {
				findedPipes.push_back(pipelist[i]);
			}
		}
	}

	if (name != "0") {
		for (int i = 0; i < sz; i++) {
			if (pipelist[i].name == name) {
				findedPipes.push_back(pipelist[i]);
			}
		}
	}

	if (name == "0" && repair == 2) {
		for (int i = 0; i < sz; i++) {
			findedPipes.push_back(pipelist[i]);
		}
	}
}

void pipeid(vector <pipe> pipelist, vector <pipe> findedPipes) {
	findedPipes.clear();
	int n = 0;
	int id = 0;
	wInput("количество редактируемых труб", n);
	for (int i = 0; i < n; i++) {
		string stri = to_string(i+1);
		wInput("id " + stri + " трубы", id);
		findedPipes.push_back(pipelist[id]);
	}
}

void pipePackEdit(vector <pipe>& pipelist, vector <pipe>& findedPipes) {
	int sz = findedPipes.size();
	int szall = pipelist.size();
	for (int j = 0; j < sz; j++) {
		findedPipes[j].repair = !findedPipes[j].repair;
		for (int i = 0; i < szall; i++) {
			if (findedPipes[j].id == pipelist[i].id) {
				pipelist[i] = findedPipes[j];
			}
		}
	}
}

//Компрессорные станции
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
	for (int i = 0; i <= (kslist.size()-1); i++) {
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

void findKS(vector <KS> KSlist, vector <KS>& findedKS) {
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
			if ((KSlist[i].amountShops-KSlist[i].activeShops)/KSlist[i].amountShops == inactive) {
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

void KSid(vector <KS> KSlist, vector <KS> findedKS) {
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

void KSPackEdit(vector <KS>& KSlist, vector <KS>& findedKS) {
	//остановился тут, сделать редактирование кс
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

//работа с файлами
void save(vector <pipe> pipelist, vector <KS> KSlist)
{
	ofstream fout;
	fout.open("Pipes.txt", ios::out);
	if (fout.is_open()) {
		fout << pipelist.size() << endl;
		for (int i = 0; i < pipelist.size(); i++) {
			fout << pipelist[i].id << endl;
			fout << pipelist[i].name << endl;
			fout << pipelist[i].lenght << endl;
			fout << pipelist[i].diameter << endl;
			fout << pipelist[i].repair << endl;
		}
	}
	fout.close();
	//ofstream fout;
	fout.open("KS.txt", ios::out);
	if (fout.is_open()) {
		fout << KSlist.size() << endl;
		for (int i = 0; i < KSlist.size(); i++) {
			fout << KSlist[i].id << endl;
			fout << KSlist[i].name << endl;
			fout << KSlist[i].amountShops << endl;
			fout << KSlist[i].activeShops << endl;
			fout << KSlist[i].efficiency << endl;
		}
	}
	fout.close();
}

void loadpipe(vector <pipe>& pipelist)
{
	ifstream fin;
	fin.open("Pipes.txt", ios::in);
	if (fin.is_open()) {
		int sz1;
		fin >> sz1;
		for (int i = 0; i < sz1; i++) {
			pipe p;
			pipelist.push_back(p);
			fin >> pipelist[i].id;
			fin >> pipelist[i].name;
			fin >> pipelist[i].lenght;
			fin >> pipelist[i].diameter;
			fin >> pipelist[i].repair;
		}
	}
	fin.close();
}

void loadKS(vector <KS>& KSlist)
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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //https://nicknixer.ru/programmirovanie/russkie-simvolybukvy-pri-vvodevyvode-v-konsol-na-c/
	int choise;
	pipe p;
	KS k;
	vector <pipe> pipelist;
	vector <KS> KSlist;
	int maxid = 0;
	int maxid2 = 0;
	int i = 0;
	vector <pipe> findedPipes;
	vector <KS> findedKS;

	p.id = 0; //idle initialize
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
		cout << "8 - Сохранить данные в текстовые документы" << endl;
		cout << "9 - Загрузить данные из текстовых документов" << endl;
		cout << "10 - Поиск труб по фильтру" << endl;
		cout << "11 - Поиск компрессорных станций по фильтру" << endl;
		cout << "12 - Выбор труб для пакетного редактирования по id" << endl;
		cout << "13 - Выбор КС для пакетного редактирования по id" << endl;
		cout << "14 - Пакетное редактирование труб" << endl;
		cout << "15 - Пакетное редактирование КС" << endl;
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
		if (choise >=0 && choise <=15) {
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
				addKS(KSlist, k, maxid2);
				break;
			case 5:
				editKS(KSlist, i);
				break;
			case 6:
				deleteKS(KSlist);
				break;
			case 7:
				cout << "Трубы: " << endl << endl;
				outpipe(pipelist);
				cout << endl << "Компрессорная станция:" << endl << endl;
				outKS(KSlist);
				break;
			case 8:
				if (maxid != 0 || maxid2 != 0) {
					save(pipelist, KSlist);
				}
				else { cout << "Нет данных для сохранения" << endl; }
				break;
			case 9:
				loadpipe(pipelist);
				loadKS(KSlist);
				break;
			case 10:
				//filter-based searching done
				findPipe(pipelist, findedPipes);
				if (findedPipes.size() != 0) {
					outpipe(findedPipes);
				}
				break;
			case 11:
				findKS(KSlist, findedKS);
				if (findedKS.size() != 0) {
					outKS(findedKS);
				}
				break;
			case 12:
				pipeid(pipelist, findedPipes);
				break;
			case 13:
				KSid(KSlist, findedKS);
				break;
			case 14:
				pipePackEdit(pipelist, findedPipes);
				break;
			case 15:
				KSPackEdit(KSlist, findedKS);
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