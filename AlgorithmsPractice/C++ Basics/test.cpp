#include <iostream>
#include <list>
#include <vector>
#include<stack>

using namespace std;

class Graph
{

int V;
list<int> *adj;

public:
	Graph(int v):V(v)
		{  adj = new list<int>[V]; 	};

	void addEdge(int u, int v);
	void DFS_usingStack(int s);
	void BFS_usingQueue(int s);
	void DFS_recursive(int s);
	void BFS_recursive(int s);
	void DFSrec(int v, bool visited[]);


};


void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::DFS_usingStack(int s)
{

	vector <bool> visited (V, false);

	stack <int> stack;

	stack.push(s);

	while(!stack.empty())
	{

		s =  stack.top();
		stack.pop();


		if(!visited[s])
		{
				cout<<s<<" ";
				visited[s] = true;
		}


         list <int> :: iterator it;
		for( it = adj[s].begin(); it != adj[s].end(); ++it)
		{
			if(!visited[*it])
				stack.push(*it);
		}
	}

}



void Graph::DFS_recursive(int s)
{

	bool * visited = new bool[V];
	for (int i = 0; i< V; i++)
		visited[i] = false;

	DFSrec(s,visited);

}

void Graph::DFSrec(int v, bool visited[])
{

	visited[v] =  true;
	cout << v <<" ";
	list <int> :: iterator i;
	for( i =  adj[v].begin(); i != adj[v].end(); ++i)
	{
		if(!visited[*i])
			DFSrec(*i, visited);

	}
}



int main()
{

cout<<"Hello Test\n";


Graph G(5);
G.addEdge(1,0);
G.addEdge(0,2);
G.addEdge(2,1);
G.addEdge(0,3);
G.addEdge(1,4);

cout<<"\nDFS_usingStack : ";
G.DFS_usingStack(0);
cout<<"\nDFSrec  :  ";
G.DFS_recursive(0);

}