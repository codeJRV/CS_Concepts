#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{

	int V;
	list<int> *adj;

  public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int s); 
};

Graph::Graph(int V)
{

	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add W to V's list.
}

void Graph::DFS(int s)
{

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false; //first set all visited to zero

	stack<int> stack;

	stack.push(s);

	while (!stack.empty())
	{

		s = stack.top();
		stack.pop();

		if (!visited[s])
		{

			cout << s << " ";
			visited[s] = true;
		}

		list<int>::iterator i;

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
			if (!visited[*i])
				stack.push(*i);
	};
}

int main()
{

	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Doing DFS from node 1 : ";
	g.DFS(1);

	return 0;
}