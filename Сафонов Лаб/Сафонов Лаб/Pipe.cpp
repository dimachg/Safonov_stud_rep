#include "Pipe.h"
#include "utility.h"

using namespace std;


void Pipe::addpipe(Pipe p, int maxid)
{
	p.id = ++maxid;
	wInput("длину", p.lenght);
	wInput("диаметр", p.diameter);
	p.repair = false;
}


void Pipe::outpipe(const Pipe& p)
{
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

void Pipe::editPipe(bool& b)
{
	b = !b;
}
