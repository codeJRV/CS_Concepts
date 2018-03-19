from collections import defaultdict


class Graph:

	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, u, v):
		self.graph[u].append(v)

	def DFS(self,start):
		path = []
		stack = [start]
		while stack != []:
			v = stack.pop()
			if v not in path:
				path.append(v)
				print v
			for w in reversed(self.graph[v]):
				if w not in path:
					stack.append(w)





g = Graph()
g.addEdge(0,1)
g.addEdge(0,2)
g.addEdge(1,2)
g.addEdge(2,0)
g.addEdge(2,3) 
g.addEdge(3,3) 

print("DFS Graph is as follows")
g.DFS(2)
