#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define n 64
/***********************************
contributed by sanketpathak64
This is array implementation of stack
program for evaluation of postfix expression 123*+5- => 2
***********************************/

//array for stack & index var
int Stack[n],top = -1;

//function to check if stack is empty
bool isEmpty()
{
	return top == -1;
}

//function to check if stack is full
bool isFull()
{
	return top == n-1;
}

//function to pop a element
int pop()
{
	return Stack[top--];	
}

//function to push element in stack
void push(int data)
{
	Stack[++top] = data;
}

bool isNumber(char c)
{
	if(c > 47 && c < 58)
		return true;
	return false;
}



int main()
{
	cout<< "Enter your postfix expression to evaluate\n";
	string exp;
	cin>> exp;
	int nn = exp.size();
	for(int i = 0;i < nn; i++)
	{
		if(isNumber(exp[i]))
			push(int(exp[i]-'0'));
		else
		{
			int x = pop();
			int y = pop();
			if(exp[i] == '+')
			{
				push(y+x);
				continue;
			}
			if(exp[i] == '/')
			{
				push(y/x);
				continue;
			}
			if(exp[i] == '-')
			{
				push(y-x);
				continue;
			}
			if(exp[i] == '*')
			{
				push(y*x);
				continue;
			}
		}
		
		
	}
	cout<<"Evaluation of your postfix expression is "<<pop();
}


