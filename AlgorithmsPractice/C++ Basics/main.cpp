#include <iostream>
#include <bits/stdc++.h>
#include <list>

using namespace std;

class Graph
{

	int V,
	list<int> *adj;

public:
	Graph(int V);
	void addEdge(int u, int v);
	void DFS(int s);
	void BFS(int s);
	

};


Graph::Graph(int V)
{

	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v )
{
	adj[u].push_back(w);
} 

void Graph::DFS(int s)
{

vector <bool> visited(V,false);
stack<int> stack;
stack.push(s);


}


int main()
{




return 0;

}