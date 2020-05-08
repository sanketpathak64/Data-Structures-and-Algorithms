#include <bits/stdc++.h> 
using namespace std; 
  
// Function to perform Ternary Search 
void ternarySearch(int l, int r, int key, int ar[]) 
{ 
	
    if (r >= l) 
	{
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
  
        // Check if key is present at any mid 
        if (ar[mid1] == key)
		{
			cout<<"The index of element is ";
			cout<<mid1<<endl;
			return;
		} 
            
        if (ar[mid2] == key)
		{
			cout<<"The index of element is ";
			cout<<mid2<<endl;
			return;	
		}
  
        if (key < ar[mid1])
            ternarySearch(l, mid1 - 1, key, ar); 
        else if (key > ar[mid2])
            ternarySearch(mid2 + 1, r, key, ar); 
        else
            ternarySearch(mid1 + 1, mid2 - 1, key, ar); 
        
    } 
}


int main()
{
	int N;
    cout<<"number of elements\n";
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)
    {
		cout<<"Enter a["<< i <<"] ";
        cin>>a[i];
    }
    int key;
    cout<<"Enter search value\n";
    cin>>key;
    ternarySearch(0,N-1,key,a);
}
