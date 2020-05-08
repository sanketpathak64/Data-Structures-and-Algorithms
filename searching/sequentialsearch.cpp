#include<bits/stdc++.h>
using namespace std;
void seqsearch(int a[],int n,int sv)
{
	cout<<"index of your search value is ";
	for(int i=0;i<n;i++)
	{
		if(a[i]==sv)
		{
			cout<<i<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
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
    seqsearch(a,N,key);
}
