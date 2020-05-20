#include <bits/stdc++.h> 
using namespace std;
//to indentify if string contains unique character without using additional DS
bool isUnique(string s)
{
	int checker = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int val = s[i]-'a';	
		if(checker & (1<<val)>0)
			return 0;
		checker|=(1<<val);
	}
	return 1;
	
} 
int main()
{
	string a;
	cin>>a; 
	cout<<isUnique(a);
}
