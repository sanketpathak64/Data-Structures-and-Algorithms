#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define N 64
/***********************************
contributed by sanketpathak64
This is array implementation of stack
program to find whether expression's parenthesis are balanced or not
Example => valid {}, {[()]}, {([{}])}
invalid {[(]}), {]

'{' can't go inside '[', '('
'[' can't go inside '('
***********************************/
char Stack[N];

int top = -1;
bool isEmpty()
{
	return top == -1;
}


bool isFull()
{
	return top == N-1;
}

char pop()
{
	return Stack[top--];	
}

void push(char data)
{
	Stack[++top] = data;
}



int main()
{
	string exp;
	cout<< "enter your expression\n";
	cin>> exp;
	int n = exp.size();
	
	for(int i=0;i<n;i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			if(exp[i] == '{')
			{
				if(Stack[top]=='[' || Stack[top]=='(')
				{
					cout<<"\nInvalid expression\n";
					return 0;
				}
			}
			else if(exp[i] == '[')
			{
				if(Stack[top]=='(')
				{
					cout<<"\nInvalid expression\n";
					return 0;
				}
			}
			push(exp[i]);
			
		}
		else
		{
			if(exp[i] == ']' || exp[i] == ')' || exp[i] == '}')
			{
				if(isEmpty())
				{
					cout<<"\nYour expression is not balanced\n";
					return 0;
				}
				char x=pop();
				
				
				
				
				if((exp[i]==')' && x!='(') || (exp[i]==']' && x!='[') || (exp[i]=='}' && x!='{')) 
				{
					cout<<"\nYour expression is not balanced\n";
					return 0;
				}
			}
			else
			{
				continue;
			}
		}
	}
	if(isEmpty())
		cout<<"\nYour expression is perfectly valid\n";
	else
	{
		cout<<"\nYour expression is not balanced\n";
		return 0;
	}
}
