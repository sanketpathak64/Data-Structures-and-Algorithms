#include <iostream> 
#include <queue> 
using namespace std; 
int main () 
{   
    priority_queue <int> max_heap; 
    max_heap.push(10); 
    max_heap.push(30); 
    max_heap.push(20); 
    max_heap.push(5); 
    max_heap.push(1); 
    cout<<"Element at top of Max Heap at every step:\n";
    while(!max_heap.empty())
    {   
        // Print Top Element
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }
    
    // DECLARING MIN HEAP
    priority_queue <int, vector<int>, greater<int> > min_heap; 
    
    // Add elements to the Min Heap
    // in any order
    min_heap.push(10); 
    min_heap.push(30); 
    min_heap.push(20); 
    min_heap.push(5); 
    min_heap.push(1); 
    cout<<"\n\nElement at top of Min Heap at every step:\n";
    while(!min_heap.empty())
    {   
        // Print Top Element
        cout<<min_heap.top()<<" ";
        
        // Remove Top Element
        min_heap.pop();
    }

    return 0; 
} 
