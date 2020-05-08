#include<bits/stdc++.h>
using namespace std;

int bin_search(int A[],int left,int right,int k);

int main()
{
    int t;
    cout<<"Testcases\n";
    cin>>t;

    while(t--)
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
        int found = bin_search(a,0,N-1,key);
        cout<<"index of your key is "<<found<<endl;
    }
}

int bin_search(int A[], int l, int r, int k)
{
   int mid = (l + r) / 2;
   while(l<=r)
   {
       if(A[mid]==k)
            return mid;
       if(A[mid]>k)
       {
           r=mid-1;
       }
       else
       {
           
           l=mid+1;
       }
       mid=(l+r)/2;
   }
   return -1;
}
