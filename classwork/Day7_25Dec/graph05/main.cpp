/*****************************************************************
* File: main.cpp
* Batch: DAC Feb 2020 @ Sunbeam Infotech
* Created on: 25-Dec-2020
* Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
******************************************************************/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define INF 999
#define MAX 10

class AdjMatNonWeightedGraph {
private:
	int mat[MAX][MAX];
	int vertCount, edgeCount;
public:
	AdjMatNonWeightedGraph(int vertexCount) {
		int i, j;
		edgeCount = 0;
		vertCount = vertexCount;
		for(i=0; i<vertCount; i++) {
			for(j=0; j<vertCount; j++)
				mat[i][j] = 0;
		}
	}
	void accept() {
		cout << "enter number of edges: ";
		cin >> edgeCount;
		for(int c=0; c<edgeCount; c++) {
			int from, to;
			cout << "enter edge (from to): ";
			cin >> from >> to;
			mat[from][to] = 1;
			mat[to][from] = 1; // comment this line for Directed graph.
		}
		cout << endl;
	}
	void display() {
		cout << "Adjacency Matrix: " << endl;
		for (int i = 0; i < vertCount; ++i) {
			for (int j = 0; j < vertCount; ++j)
				cout << mat[i][j] << "\t";
			cout << endl;
		}
	}

	void bfsTrav(int start) {
		bool marked[MAX];
		queue<int> q;
		cout << "BFS : ";
		for(int v=0; v<vertCount; v++)
			marked[v] = false;
		q.push(start);
		marked[start] = true;
		while(!q.empty()) {
			int trav = q.front();
			q.pop();
			cout << trav << ", ";
			for(int dest=0; dest<vertCount; dest++) {
				if(mat[trav][dest] != 0 && !marked[dest]) {
					q.push(dest);
					marked[dest] = true;
				}
			}
		}
		cout << endl;
	}

	void bfsSpanningTree(int root) {
		bool marked[MAX];
		queue<int> q;
		cout << "BFS Spanning Tree: " << endl;
		for(int v=0; v<vertCount; v++)
			marked[v] = false;
		q.push(root);
		marked[root] = true;
		while(!q.empty()) {
			int trav = q.front();
			q.pop();
			for(int dest=0; dest<vertCount; dest++) {
				if(mat[trav][dest] != 0 && !marked[dest]) {
					q.push(dest);
					marked[dest] = true;
					cout << trav << " -> " << dest << endl;
				}
			}
		}
		cout << endl;
	}

	void singleSourcePathLength(int source) {
		bool marked[MAX];
		int dist[MAX];
		queue<int> q;
		for(int v=0; v<vertCount; v++) {
			marked[v] = false;
			dist[v] = INF;
		}
		q.push(source);
		marked[source] = true;
		dist[source] = 0;
		while(!q.empty()) {
			int trav = q.front();
			q.pop();
			for(int dest=0; dest<vertCount; dest++) {
				if(mat[trav][dest] != 0 && !marked[dest]) {
					q.push(dest);
					marked[dest] = true;
					dist[dest] = dist[trav] + 1;
				}
			}
		}
		cout << "Distance of vertices from vertex " << source << " : " << endl;
		for(int i=0; i<vertCount; i++)
			cout << " to vertex " << i << " = " << dist[i] << endl;
		cout << endl;
	}

	bool isBipartite() {
		enum colors { GREEN=-1, NOCOLOR=0, BLUE=1 };
		int start = 0;
		int color[MAX];
		queue<int> q;
		for(int v=0; v<vertCount; v++)
			color[v] = NOCOLOR;
		q.push(start);
		color[start] = GREEN;
		while(!q.empty()) {
			int trav = q.front();
			q.pop();
			for(int dest=0; dest<vertCount; dest++) {
				if(mat[trav][dest] != 0) {
					if(color[dest] == color[trav])
						return false;
					if(color[dest] == NOCOLOR) {
						color[dest] = -1 * color[trav];
						q.push(dest);
					}
				}
			}
		}
		return true;
	}

	void dfsTrav(int start) {
		bool marked[MAX];
		stack<int> s;
		cout << "DFS : ";
		for(int v=0; v<vertCount; v++)
			marked[v] = false;
		s.push(start);
		marked[start] = true;
		while(!s.empty()) {
			int trav = s.top();
			s.pop();
			cout << trav << ", ";
			for(int dest=0; dest<vertCount; dest++) {
				if(mat[trav][dest] != 0 && !marked[dest]) {
					s.push(dest);
					marked[dest] = true;
				}
			}
		}
		cout << endl;
	}

	bool isConnected() {
		int start = 0, count = 0;
		bool marked[MAX];
		stack<int> s;
		for(int v=0; v<vertCount; v++)
			marked[v] = false;
		s.push(start);
		marked[start] = true;
		count++;
		while(!s.empty()) {
			int trav = s.top();
			s.pop();
			for(int dest=0; dest<vertCount; dest++) {
				if(mat[trav][dest] != 0 && !marked[dest]) {
					s.push(dest);
					marked[dest] = true;
					count++;
					if(count == vertCount)
						return true;
				}
			}
		}
		return false;
	}

	void dfsSpanningTree(int root) {
		bool marked[MAX];
		stack<int> s;
		cout << "DFS Spanning Tree: " << endl;
		for(int v=0; v<vertCount; v++)
			marked[v] = false;
		s.push(root);
		marked[root] = true;
		while(!s.empty()) {
			int trav = s.top();
			s.pop();
			for(int dest=0; dest<vertCount; dest++) {
				if(mat[trav][dest] != 0 && !marked[dest]) {
					s.push(dest);
					marked[dest] = true;
					cout << trav << " -> " << dest << endl;
				}
			}
		}
		cout << endl;
	}

};

int main() {
	int vertCount;
	cout << "enter number of vertices: ";
	cin >> vertCount;

	AdjMatNonWeightedGraph g(vertCount);
	g.accept();
	g.display();
	g.bfsTrav(5);
	g.dfsTrav(0);
	cout << (g.isConnected() ? "Connected graph" : "Disconnected graph") << endl;
	g.dfsSpanningTree(0);
	g.bfsSpanningTree(0);
	g.singleSourcePathLength(0);
	cout << (g.isBipartite() ? "Bipartite graph" : "Not Bipartite graph") << endl;
	return 0;
}

/*
6
7
0 1
0 2
0 3
1 2
1 4
3 4
3 5
*/



