#include <iostream>
#include <list>

using namespace std;

class Graph
{

	int V;
	list <int> *adj;

public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int s);
	void DFSUtil(int v, bool visited[]);

};

Graph::Graph (int V)
{

	this -> V  = V;
	adj =  new list<int> [V];

}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);  // Add W to V's list.

}

void Graph::DFS(int v)
{
	// first of all assign all the nodes as unvisited

	bool *visited  = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	//send to DFSutil
	DFSUtil(v,visited);

}

void Graph::DFSUtil(int v, bool visited[])
{

	visited[v] = true;
	cout<<v<<" ";

	list<int>::iterator i;
	for( i = adj[v].begin(); i!=adj[v].end(); ++i)
	{

		if(!visited[*i])
			DFSUtil(*i, visited);
	}
}

int main()
{

	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	cout<<"Doing Recursive DFS from node 1 : ";
	g.DFS(1);

	return 0;

}