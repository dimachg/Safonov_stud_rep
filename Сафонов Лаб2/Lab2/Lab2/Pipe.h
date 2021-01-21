#pragma once
#include <string>

using namespace std;

class Pipe
{
public:
	int id;
	std::string name;
	float lenght;
	int diameter;
	bool repair;
	double getPressureDropValue() const;
	double getPerformance() const;

	friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& pipe);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& pipe);
	friend std::istream& operator >> (std::istream& in, Pipe& pipe);

	void addpipe(vector <Pipe>& pipelist, Pipe p, int& maxid);
	void deletepipe(vector <Pipe>& pipelist);
	void outpipe(vector <Pipe> pipelist);
	void editPipe(vector <Pipe>& pipelist);
	void findPipe(vector <Pipe> pipelist, vector <Pipe>& findedPipes);
	void pipeid(vector <Pipe> pipelist, vector <Pipe> findedPipes);
	void pipePackEdit(vector <Pipe>& pipelist, vector <Pipe>& findedPipes);
	void loadpipe(vector <Pipe>& pipelist);

};
