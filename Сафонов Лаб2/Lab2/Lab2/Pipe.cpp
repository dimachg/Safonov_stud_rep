#include <vector>
#include <iostream>
#include <fstream>
#include "Pipe.h"
#include "utils.h"

using namespace std;

void Pipe::addpipe(vector <Pipe>& pipelist, Pipe p, int& maxid)
{
	p.id = maxid;
	cout << "����������, ������� ���" << endl;
	cin.ignore();
	getline(cin, p.name);
	wInput("�����", p.lenght);
	wInput("�������", p.diameter);
	p.repair = false;
	pipelist.push_back(p);
	maxid++;
}

void Pipe::deletepipe(vector<Pipe>& pipelist)
{
	int i;
	wInput("����� ���������� ��������", i);
	pipelist[i].lenght = 0;
}

void Pipe::outpipe(vector<Pipe> pipelist)
{
	int i = 0;
	for (i = 0; i <= (pipelist.size() - 1); i++)
	{
		if (pipelist[i].lenght != 0 && pipelist[i].diameter != 0) {
			cout << "id: " << pipelist[i].id << endl;
			cout << "���: " << pipelist[i].name << endl;
			cout << "����� �����: " << pipelist[i].lenght << endl;
			cout << "������� �����: " << pipelist[i].diameter << endl;
			if (pipelist[i].repair == false) {
				cout << "����� ��������" << endl;
			}
			else {
				cout << "����� � �������" << endl;
			}
		}

	}
}

void Pipe::editPipe(vector<Pipe>& pipelist)
{
	int i;
	wInput("����� ���������� �����", i);
	pipelist[i].repair = !pipelist[i].repair;
}

void Pipe::findPipe(vector<Pipe> pipelist, vector<Pipe>& findedPipes)
{
	findedPipes.clear();
	string name;
	int repair;
	cout << "������� ������ �� ����� ��� 0 ��� ���������� �������" << endl;
	cin.ignore();
	getline(cin, name);
	wInput("������ �� ������� ������ 1-��� 0-� ������� 2-��������� �������", repair);
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

void Pipe::pipeid(vector<Pipe> pipelist, vector<Pipe> findedPipes)
{
	findedPipes.clear();
	int n = 0;
	int id = 0;
	wInput("���������� ������������� ����", n);
	for (int i = 0; i < n; i++) {
		string stri = to_string(i + 1);
		wInput("id " + stri + " �����", id);
		findedPipes.push_back(pipelist[id]);
	}
}

void Pipe::pipePackEdit(vector<Pipe>& pipelist, vector<Pipe>& findedPipes)
{
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

void Pipe::loadpipe(vector<Pipe>& pipelist)
{
	ifstream fin;
	fin.open("Pipes.txt", ios::in);
	if (fin.is_open()) {
		int sz1;
		fin >> sz1;
		for (int i = 0; i < sz1; i++) {
			Pipe p;
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

double Pipe::getPressureDropValue() const
{
	return lenght * 1.0 / diameter;
}

double Pipe::getPerformance() const
{
	return diameter * 1.0 / lenght;
}
