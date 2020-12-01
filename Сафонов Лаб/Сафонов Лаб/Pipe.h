#pragma once
#include <string>
#include <iostream>
#include "utility.h"

using namespace std;

class Pipe
{
public:
	int id;
	float lenght;
	int diameter;
	bool repair;

	Pipe addpipe(int maxid);

	void outpipe(const Pipe& p);


	void editPipe(bool& b);
};

