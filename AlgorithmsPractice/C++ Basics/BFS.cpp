#include <iostream>
#include <list>

using namespace std;

////BFS using queue method is as follows ////


////////////////////// Step 1 : Create a graph where the vertices are an adjacency list 

class Graph
{

	int V;
	list<int> *adj;

public:

	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);

};

Graph::Graph(int V)
{

	this -> V = V;
	adj = new list<int> [V];
}

/////  Adding edge b/w v and w implies pushing back the vector w in the v's adjacency list

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

/////  Now the main BFS algorithm is as follows

void Graph::BFS(int s)
{

	bool *visited = new bool[V];
	for (int i = 0; i <V; i++)
		visited[i] = false;				//first set all visited to zero

	list<int> queue;					//create a queue for BFS

	///Mark current node as visited and enque it 


	visited[s] = true;
	queue.push_back(s);  //add s to the queue

	list <int> :: iterator i;   ///create an iterator

	while(!queue.empty())
	{

		//pop out the first vertex and print it	
		s = queue.front();

		cout << s << " ";
		queue.pop_front();

		//now iterate through the adjacent vertices of the s vertex and add it to the queue if its not been visited

		for (  i = adj[s].begin(); i != adj[s].end(); ++i)  //note here i is the iterator, which is basically a pointer
		{

			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}


	};

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

	cout<<"Doing BFS from node 1 : ";
	g.BFS(1);

	return 0;

}