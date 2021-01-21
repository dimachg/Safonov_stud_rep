#pragma once
#include <string>
#include <vector>

using namespace std;

class KS
{
public:
	int id;
	std::string name;
	int amountShops;
	int activeShops;
	float efficiency;

	friend std::ostream& operator << (std::ostream& out, const KS& CS);
	friend std::ofstream& operator << (std::ofstream& fout, const KS& CS);
	friend std::ifstream& operator >> (std::ifstream& fin, KS& CS);
	friend std::istream& operator >> (std::istream& in, KS& CS);

	void addKS(vector <KS>& kslist, KS k, int& maxid2);
	void deleteKS(vector <KS>& kslist);
	void outKS(vector <KS> kslist);
	void editKS(vector <KS>& kslist, int i);
	void findKS(vector <KS> KSlist, vector <KS>& findedKS);
	void KSid(vector <KS> KSlist, vector <KS> findedKS);
	void KSPackEdit(vector <KS>& KSlist, vector <KS>& findedKS);
	void loadKS(vector <KS>& KSlist);
};
