#include "Pipe.h"
#include "utility.h"

using namespace std;

Pipe Pipe::addpipe(int maxid)
{
	Pipe p;
	p.id = ++maxid;
	wInput("�����", p.lenght);
	wInput("�������", p.diameter);
	p.repair = false;
	return p;
}

void Pipe::outpipe(const Pipe& p)
{
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

void Pipe::editPipe(bool& b)
{
	b = !b;
}
