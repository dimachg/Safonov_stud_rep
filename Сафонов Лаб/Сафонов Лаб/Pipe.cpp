#include "Pipe.h"
#include "utility.h"

using namespace std;


void Pipe::addpipe(Pipe p, int maxid)
{
	p.id = ++maxid;
	wInput("�����", p.lenght);
	wInput("�������", p.diameter);
	p.repair = false;
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
