#pragma once
#include <string>
#include <iostream>
#include "utility.h"

using namespace std;

class KS
{

public:
	int id;
	string name;
	int amountShops;
	int activeShops;
	float efficiency;

	void addKS(KS k, int maxid);

	void outKS(const KS& k);

	void editKS(KS& k);

};

