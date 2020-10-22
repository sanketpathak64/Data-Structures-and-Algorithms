// C++ program to check whether a given graph is Bipartite or not 
#include<bits/stdc++.h> 
using namespace std; 
const int MAX = 1001;
int adj[MAX][MAX];
bool isBipartite(int src,int V) 
{ 
	int colorArr[V]; 
	for (int i = 0; i < V; ++i) 
		colorArr[i] = -1; 
	colorArr[src] = 1; 
	queue <int> q; 
	q.push(src);  
	while (!q.empty()) 
	{ 
		int u = q.front(); 
		q.pop(); 
		if (adj[u][u] == 1) 
		return false; 
		for (int v = 0; v < V; ++v) 
		{ 
			if (adj[u][v] && colorArr[v] == -1) 
			{ 
				colorArr[v] = 1 - colorArr[u]; 
				q.push(v); 
			} 
			else if (adj[u][v] && colorArr[v] == colorArr[u]) 
				return false; 
		} 
	} 
	return true; 
} 
int main() 
{ 
	int V,E;
	cin>>V>>E;
	memset(adj,0,sizeof adj);
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	if(isBipartite(0,V))
		cout << "Given graph is Bipartite";
	else
		cout << "Given graph is NOT Bipartite"; 
	return 0; 
} 
