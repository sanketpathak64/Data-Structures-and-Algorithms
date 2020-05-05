//Factorial of positive number is product of numbers less than equal to that number till 1

//It is denoted by !

// n factorial is Denoted by n!=n*(n-1)*(n-2)*(n-3)*........*3*2*1.

//Note that the 0!=1 and 1!=1 always

//Now                          n!=n*[(n-1)*(n-2)*(n-3)*........*3*2*1].
//From above we can say that   n!=n*(n-1)!

//Hence  Factorial(n) = n*Factorial(n-1)

#include<iostream>
using namespace std;
int Fact(int n)
{
  //As 0!=1 and 1!=1 always
	if(n==0 || n==1)
	return 1;
	//Factorial(n) = n*Factorial(n-1)
  else
	return n*Fact(n-1);
}

int main()
{
	int res,n;
	int Fact(int n);
  //Take input from user to calculate factorial
	cout<<"Enter No:\n";
	cin>>n;
	res=Fact(n);
	cout<<"Factorial:"<<res;
	return 0;
}
