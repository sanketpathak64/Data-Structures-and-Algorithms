#include<bits/stdc++.h> 
using namespace std;
int V=5;
vector<int> adj[5]; 
bool visited[5];
void addEdge( int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 
void printGraph( int V) 
{ 
	for (int v = 0; v < V; ++v) 
	{ 
		cout << "\n Adjacency list of vertex "
			<< v << "\n head "; 
		for (auto x : adj[v]) 
		cout << "-> " << x; 
		printf("\n"); 
	} 
} 
BFS(int s) 
{  
    for(int i = 0; i < V; i++) 
    	visited[i] = false; 
    list<int> queue; 
  	visited[s] = true; 
    queue.push_back(s); 
//  	list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front();
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 



int main() 
{ 
	
	addEdge( 0, 1); 
	addEdge( 0, 4); 
	addEdge(1, 2); 
	addEdge( 1, 3); 
	addEdge(1, 4); 
	addEdge( 2, 3); 
	addEdge(3, 4); 
	printGraph( V); 
	BFS(0);
	
	return 0; 
} 

