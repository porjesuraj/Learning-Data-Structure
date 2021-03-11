/*****************************************************************
* File: main.cpp
* Batch: DAC Feb 2020 @ Sunbeam Infotech
* Created on: 25-Dec-2020
* Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
******************************************************************/

#include <iostream>
#include <list>
using namespace std;

#define MAX 10

class Edge {
public:
	int src, dest, weight;
public:
	Edge(int s=0, int d=0, int wt=0) {
		src = s;
		dest = d;
		weight = wt;
	}
	void display() {
		cout << "(" << src << "-" << dest << "|" << weight << ")";
	}
};

class AdjListWeightedGraph {
private:
	list<Edge> arr[MAX];
	int vertCount, edgeCount;
public:
	AdjListWeightedGraph(int vertexCount) {
		edgeCount = 0;
		vertCount = vertexCount;
	}
	void accept() {
		cout << "enter number of edges: ";
		cin >> edgeCount;
		for(int c=0; c<edgeCount; c++) {
			int from, to, weight;
			cout << "enter edge (from to weight): ";
			cin >> from >> to >> weight;
			Edge e1(from, to, weight);
			arr[from].push_back(e1);
			Edge e2(to, from, weight);
			arr[to].push_back(e2); // comment this for directed graph
		}
	}
	void display() {
		cout << "Adjacency List: " << endl;
		for(int i=0; i<vertCount; i++) {
			cout << "vert " << i << " :: ";
			list<Edge>::iterator itr = arr[i].begin();
			while(itr != arr[i].end()) {
				itr->display();
				cout << " -> ";
				itr++;
			}
			cout << endl;
		}
	}
};

int main() {
	int vertCount;
	cout << "enter number of vertices: ";
	cin >> vertCount;

	AdjListWeightedGraph g(vertCount);
	g.accept();
	g.display();
	return 0;
}

/*
6
7
0 1 7
0 2 4
0 3 8
1 2 9
1 4 5
3 4 6
3 5 2
*/

