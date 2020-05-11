#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
//this file contains some basic recursive functions

//print numbers from 1 to n
void printNos(int N)
{
    //Your code here
    if(N==0)
        return;
    printNos(N-1);
    cout<<N<<" ";
}

//function to find sum of numbers
int sumOfDigits(int n)
{
    //Your code here
    if(n==0)
        return 0;
    int x=n%10;
    return x+sumOfDigits(n/10);
}

//program to find nth fibonacci
long long fibonacci(int n)
{
    //Your code here
    if(n==1 || n==0)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}


//call required function in main
int main()
{
	
}
