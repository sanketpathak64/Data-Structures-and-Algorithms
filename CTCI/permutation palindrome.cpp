#include<iostream>
using namespace std;
//O(n) time O(1)space
int main()
{
	string a;
	cin>>a;
	int n=a.size();
	int x=0;
	for(int i=0;i<n;i++)
	{
		x^=(a[i]-'a');
	}
	if(x==0)
	{
		cout<<"palindrome";
		return 0;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(x==a[i]-'a')
			{
				cout<<"palindrome";
				return 0;
			}
		}
	}
	cout<<"No palindrome";
}
