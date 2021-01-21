#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include "Pipe.h"
#include "KS.h"
#include "Graph.h"

using namespace std;

//работа с файлами
void save(vector <Pipe> pipelist, vector <KS> KSlist)
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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //https://nicknixer.ru/programmirovanie/russkie-simvolybukvy-pri-vvodevyvode-v-konsol-na-c/
	int choise;
	Pipe p;
	KS k;
	vector <Pipe> pipelist;
	vector <KS> KSlist;
	int maxid = 0;
	int maxid2 = 0;
	int i = 0;
	vector <Pipe> findedPipes;
	vector <KS> findedKS;
	Graph gasNetwork;
	unordered_map <int, KS> mapKS;
	unordered_map <int, Pipe> mapPipe;

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
		cout << "16 - Go to gas network menu" << endl;
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
				p.addpipe(pipelist, p, maxid);
				break;
			case 2: 
				p.deletepipe(pipelist);
				break;
			case 3:
				p.editPipe(pipelist);
				break;
			case 4:
				k.addKS(KSlist, k, maxid2);
				break;
			case 5:
				k.editKS(KSlist, i);
				break;
			case 6:
				k.deleteKS(KSlist);
				break;
			case 7:
				cout << "Трубы: " << endl << endl;
				p.outpipe(pipelist);
				cout << endl << "Компрессорная станция:" << endl << endl;
				k.outKS(KSlist);
				break;
			case 8:
				if (maxid != 0 || maxid2 != 0) {
					save(pipelist, KSlist);
				}
				else { cout << "Нет данных для сохранения" << endl; }
				break;
			case 9:
				p.loadpipe(pipelist);
				k.loadKS(KSlist);
				break;
			case 10:
				p.findPipe(pipelist, findedPipes);
				if (findedPipes.size() != 0) {
					p.outpipe(findedPipes);
				}
				break;
			case 11:
				k.findKS(KSlist, findedKS);
				if (findedKS.size() != 0) {
					k.outKS(findedKS);
				}
				break;
			case 12:
				p.pipeid(pipelist, findedPipes);
				break;
			case 13:
				k.KSid(KSlist, findedKS);
				break;
			case 14:
				p.pipePackEdit(pipelist, findedPipes);
				break;
			case 15:
				k.KSPackEdit(KSlist, findedKS);
			case 16:
			{
				if (mapKS.size() >= 2 && !mapPipe.empty())
				{
					bool editingNet = true;
					while (editingNet)
					{
						cout << "1 - connect compressor stations with pipe\n"
							<< "2 - do topological sorting\n"
							<< "3 - show current network\n"
							<< "4 - save network to file\n"
							<< "5 - load network from file\n"
							<< "6 - delete compressor stacion from network\n"
							<< "7 - delete pipe from network\n"
							<< "8 - change pipe\n"
							<< "9 - find maximum flow\n"
							<< "10 - find minimal path\n"
							<< "0 - exit from this menu to main menu\n";
						switch (tryInput("Please, chose an action: ", 0))
						{
						case 1:
						{
							for (auto& p : mapKS)
							{
								cout << p.first << endl;
							}
							cout << "^ all avaliable id of compressor stations" << endl;
							int IdF = tryInput("Please, enter id of first avaliable compressor station (or [0] to leave): ", mapKS);
							int IdS = tryInput("Please, enter id of second avaliable compressor station (or [0] to leave): ", mapKS);
							if (IdF != 0 && IdS != 0)
							{
								for (auto& p : mapPipe)
								{
									if (!p.second.repair && !gasNetwork.HasEdge(p.first))
									{
										cout << p.first << endl;
									}
								}
								cout << "^ all available id of pipes" << endl;
								int IdE = tryInput("Please, enter id of avaliable pipe (or [0] to leave): ", mapPipe);
								if (IdE != 0)
								{
									auto iter = mapPipe.find(IdE);
									if (!iter->second.repair && !gasNetwork.HasEdge(iter->first))
									{
										bool IsStraight = tryInput<bool>("If this pipe comes from first to second? ([0] - revers, [1] - yes): ", 0, 1);
										gasNetwork.ConnectDirected(IdF, IdS, IdE, iter->second.getPressureDropValue(), iter->second.getPerformance(), IsStraight);
									}
									else
									{
										cout << "this pipe send for repair, choose another one" << endl;
									}
								}
								else
								{
									cout << "Pipe does not exist ";
								}
							}
							break;
						}
						case 2:
						{
							cout << "topological sorting" << endl;
							auto sort = gasNetwork.TopologicalSorting();
							for (unsigned int i = 0; i < sort.size(); i++)
							{
								cout << i + 1 << "      " << sort[i] << endl;
							}
							if (!sort.empty())
							{
								if (tryInput<bool>("Would you like to see compressor stations? ([1] - yes, [0] - no): ", 0, 1))
								{
									for (int i : sort)
									{
										cout << mapKS[i];
									}
								}
							}
							else
							{
								std::cout << "has cycle" << std::endl;
							}
							break;
						}
						case 3:
						{
							cout << gasNetwork;
							break;
						}
						case 4:
						{
							string filename = "";
							cout << "Please, enter file name: ";
							cin >> filename;
							ofstream fout;
							fout.open(filename + ".txt", ios::out);
							if (fout.is_open())
							{
								fout << gasNetwork;
							}
							fout.close();
							break;
						}
						case 5:
						{
							string filename = "";
							cout << "Please, enter file name: ";
							cin >> filename;
							ifstream fin;
							fin.open(filename + ".txt", ios::in);
							if (fin.is_open())
							{
								fin >> gasNetwork;
							}
							fin.close();
							break;
						}
						case 6:
						{
							gasNetwork.DeleteVertex(tryInput("Please, enter id of compressor station you want to delete: ", mapKS));
							break;
						}
						case 7:
						{
							gasNetwork.DeleteEdge(tryInput("Please, enter id of pipe you want to delete: ", mapPipe));
							break;
						}
						case 8:
						{
							int IdO = tryInput("Please, enter id of pipe you want to replace: ", mapPipe);
							if (IdO != 0)
							{
								int IdN = tryInput("Please, enter id of pipe with which you would like to replace old one: ", mapPipe);
								if (!mapPipe[IdN].repair)
								{
									bool IsStraght = tryInput<bool>("If this pipe comes from first to second? ([0] - revers, [1] - yes): ", 0, 1);
									gasNetwork.ReplaceEdge(IdO, IdN, mapPipe[IdN].getPressureDropValue(), IsStraght);
								}
							}
							break;
						}
						case 0:
							editingNet = false;
							break;
						default:
							cout << "This action is unacceptable " << endl;
							break;
						}
					}
				}
				else
				{
					cout << "At first add pipe and compressor station " << endl;
				}
			}
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