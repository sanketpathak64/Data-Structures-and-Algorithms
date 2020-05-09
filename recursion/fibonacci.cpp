#include<bits/stdc++.h>
using namespace std;
long long fibonacci(int n)
{
    
    if(n==1 || n==0)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
	cout<<fibonacci(10);
}
