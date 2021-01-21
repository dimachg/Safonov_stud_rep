#pragma once
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include "utils.h"

class Graph
{
	struct Vertex
	{
		int OwnVertexId;
		std::unordered_set <int> EdgeIds;
		bool IsMarked;
		bool IsPassed;
	};
	struct Edge
	{
		int StartVertexId;
		int OwnEdgeId;
		int EndVertexId;
		double Weight;
		double Capacity;
		bool IsDirected;
	};
public:
	void ConnectDirected(int idVer1, int idVer2, int idEdge, double Weigth = 1.0, double Capacity = 1.0, bool IsStraight = true);
	void DeleteVertex(int id);
	void DeleteEdge(int id);
	void ReplaceEdge(int OldId, int NewId, double Weight, bool IsStraight);
	void SwapVertex(int IdF, int IdS);
	std::vector<int> TopologicalSorting() const;
	bool HasEdge(int Id) const;
	void ResetEdge(int Id, bool IsBroken, double Capacity, double Weight);
	friend std::ostream& operator << (std::ostream& out, const Graph& G);
	friend std::istream& operator >> (std::istream& in, Graph& G);
	friend std::ifstream& operator >> (std::ifstream& fin, Graph& G);
	friend std::ofstream& operator << (std::ofstream& fout, const Graph& G);
private:
	std::vector<std::vector <int>>FindAllPaths(int IdStart, int IdEnd) const;
	bool IsCycled() const;
	void StringAlert(std::string s) const;
	bool HasVertex(int Id) const;
	std::vector <Graph::Edge> GetEjectors(int Id) const;
	std::vector <int> GetAdjacent(int Id) const;
	//void DepthFirstSearch(int IdV);
	Graph::Vertex AddVertex(int ownId);
	Graph::Edge AddEdge(int startId, int ownId, int endId, double Weight, double Cap, bool IsDirected, bool StarttoEnd);
	std::map <int, Vertex> MapVertex;
	std::unordered_map <int, Edge> MapEdge;
};