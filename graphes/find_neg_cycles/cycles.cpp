/*You are given a directed graph, and your task is 
  to find out if it contains a negative cycle.*/

//Student: Gustavo Sampaio Lima
//ID: 12623992
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

struct Graph* new_graph(int V, int E) {
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

// Here we are trying to detect a negative weight cycle
int BellmanFord(struct Graph* graph, long src){
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	/* Initialize distances from src to all other
	   vertices as INFINITE */
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Relaxing all edges
	long u = 0, v = 0, weight = 0;
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			u = graph->edge[j].src;
			v = graph->edge[j].dest;
			weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	/* Check for negative-weight cycles. The above
	   step guarantees shortest distances if graph doesn't
	   contain negative weight cycle. If we get a shorter
	   path, then there is a cycle. */
	for (int i = 0; i < E; i++) {
		u = graph->edge[i].src;
		v = graph->edge[i].dest;
		weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
			return 1; // Found an negative cycle
	}

	return 0;
}

int main(){
	int V = 0, E = 0; // N = amount of nodes, M = number of edges
    cin >> V >> E;
	struct Graph* graph = new_graph(V, E);

    long int s = 0, d = 0, w = 0;
    for (int i = 0; i < E; i++){
        cin >> s >> d >> w;
        graph->edge[i].src = s;
        graph->edge[i].dest = d;
        graph->edge[i].weight = w;
    }
	
	if (BellmanFord(graph, 0))
        {cout << "YES" << endl;}
    else
        {cout << "NO" << endl;}

	return 0;
}
