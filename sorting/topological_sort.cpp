#include<iostream>
#include<list>
#include<stack>
using namespace std;
class Graph
{
	int V;
	list<int> *a;
	public:
	Graph( int v)
	{
		this->V =v;
		a=new list<int>[V];
		
	}
	void addEdge(int v,int w)
	{
		a[v].push_back(w);
		
	}
	
	void topologicalSortUtil(int i,bool visited[],stack<int>& s)
	{
		visited[i]=true;
		list<int> ::iterator itr;
		for(itr =a[i].begin();itr !=a[i].end();++itr)
		{
			if(!visited[*itr])
				topologicalSortUtil(*itr,visited,s);
				
		}
		s.push(i);
		
	}
	
	void topologicalSort()
	{
		stack<int> s;
		bool* visited = new bool[V];
		for(int i = 0; i < V; i++) 
       		 visited[i] = false; 
       		 
       	for (int i = 0; i < V; i++) 
       	{
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, s);
		}
			
		while (s.empty() == false) { 
        cout << s.top() << " "; 
        s.pop(); 
    } 
	}
};
int main()
{
	Graph g(9); 
    //g.addEdge(2,6); 
    g.addEdge(2,3); 
    g.addEdge(8,1); 
    g.addEdge(8,3); 
    g.addEdge(6,7);

	 g.addEdge(2,5);
	  g.addEdge(3,5);
	   g.addEdge(3,6);
	    g.addEdge(4,1);
		 g.addEdge(9,1);	 
    //g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph n::"; 
    g.topologicalSort(); 
    return 0; 
} 
