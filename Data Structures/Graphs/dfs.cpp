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
void DFS(int s) 
{  
    for(int i = 0; i < V; i++) 
    	visited[i] = false; 
    stack<int> st; 
  	visited[s] = true; 
    st.push(s); 

    while(!st.empty()) 
    { 
        s = st.top();
        st.pop();
		cout<<s<<" "; 
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                st.push(*i); 
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
	DFS(0);
	
	return 0; 
} 

