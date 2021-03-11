/*****************************************************************
* File: main.cpp
* Batch: DAC Feb 2020 @ Sunbeam Infotech
* Created on: 25-Dec-2020
* Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
******************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999
#define MAX 10

class Edge {
public:
	int src, dest, weight;
public:
	Edge() {
		src = 0;
		dest = 0;
		weight = 0;
	}
	Edge(int s, int d, int w) {
		src = s;
		dest = d;
		weight = w;
	}
	void display() {
		cout << src << " -> " << dest << " (" << weight << ")" << endl;
	}
};

bool compEdgeWeight(const Edge &e1, const Edge &e2) {
	return e1.weight < e2.weight;
}

class AdjMatWeightedGraph {
private:
	int mat[MAX][MAX];
	int vertCount, edgeCount;
	vector<Edge> edges;
public:
	AdjMatWeightedGraph(int vertexCount) {
		int i, j;
		edgeCount = 0;
		vertCount = vertexCount;
		for(i=0; i<vertCount; i++) {
			for(j=0; j<vertCount; j++)
				mat[i][j] = INF;
		}
	}

	void accept() {
		cout << "enter number of edges: ";
		cin >> edgeCount;
		for(int c=0; c<edgeCount; c++) {
			int from, to, weight;
			cout << "enter edge (from to): ";
			cin >> from >> to >> weight;
			mat[from][to] = weight;
			mat[to][from] = weight; // comment this line for Directed graph.
			Edge e(from, to, weight);
			edges.push_back(e);
		}
	}

	void display() {
		cout << "Adjacency Matrix: " << endl;
		for (int i = 0; i < vertCount; ++i) {
			for (int j = 0; j < vertCount; ++j) {
				if(mat[i][j] != INF)
					cout << mat[i][j] << "\t";
				else
					cout << "#" << "\t";
			}
			cout << endl;
		}
	}

	int findRoot(int v, int parent[]) {
		// traverse to the parent, until reach to root
		while (parent[v] != -1)
			v = parent[v];
		return v;
	}

	void unionSets(int srcRoot, int destRoot, int parent[]) {
		parent[srcRoot] = destRoot;
	}

	bool containsCycle(vector<Edge>& mst) {
		int parent[MAX];
		unsigned i;
		// consider each vertex as disjoint set
		for (i = 0; i < (unsigned)vertCount; i++)
			parent[i] = -1;
		// go through each edge
		for (i = 0; i < mst.size(); i++) {
			Edge e = mst[i];
			// find roots/sets of src & dest vertex
			int srcRoot = findRoot(e.src, parent);
			int destRoot = findRoot(e.dest, parent);
			// if both are in same set, cycle is detected
			if (srcRoot == destRoot)
				return true;
			// otherwise merge/union both the sets
			unionSets(srcRoot, destRoot, parent);
		}
		// if all edges are checked, but no cycle
		return false;
	}

	void kruskal() {
		vector<Edge> mst;
		unsigned i = 0;
		// sort all edges in asc order of their weights
		sort(edges.begin(), edges.end(), compEdgeWeight);
		// process each edge, until V-1 edges are added into mst
		while (mst.size() < ((unsigned)vertCount - 1)) {
			// add edge in mst & check if there is a cycle
			mst.push_back(edges[i]);
			i++;
			// if there is cycle, disard edge from mst
			if (containsCycle(mst))
				mst.pop_back();
		}
		// print mst
		int sum = 0;
		cout << "Kruskal Min Spanning Tree : " << endl;
		for (i = 0; i < mst.size(); i++) {
			mst[i].display();
			sum = sum + mst[i].weight;
		}
		cout << "sum of weights of spanning tree edges: " << sum << endl;
	}
};

int main() {
	int vertCount;
	cout << "enter number of vertices: ";
	cin >> vertCount;

	AdjMatWeightedGraph g(vertCount);
	g.accept();
	g.display();

	g.kruskal();
	return 0;
}

/*
9
14
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8
1 2 8
3 4 9
5 4 10
1 7 11
3 5 14
*/




