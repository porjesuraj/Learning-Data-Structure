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

class AdjListNonWeightedGraph {
private:
	list<int> arr[MAX];
	int vertCount, edgeCount;
public:
	AdjListNonWeightedGraph(int vertexCount) {
		edgeCount = 0;
		vertCount = vertexCount;
	}
	void accept() {
		cout << "enter number of edges: ";
		cin >> edgeCount;
		for(int c=0; c<edgeCount; c++) {
			int from, to;
			cout << "enter edge (from to): ";
			cin >> from >> to;
			arr[from].push_back(to);
			arr[to].push_back(from); // comment this for directed graph
		}
	}
	void display() {
		cout << "Adjacency List: " << endl;
		for(int i=0; i<vertCount; i++) {
			cout << "vert " << i << " :: ";
			list<int>::iterator itr = arr[i].begin();
			while(itr != arr[i].end()) {
				cout << *itr << " -> ";
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

	AdjListNonWeightedGraph g(vertCount);
	g.accept();
	g.display();
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


