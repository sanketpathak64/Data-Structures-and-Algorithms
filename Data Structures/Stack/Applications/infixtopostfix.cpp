#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define N 64
/***********************************
contributed by sanketpathak64
This is array implementation of stack
program to convert infix to postfix expression
(A+B)*C => AB+C*
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

bool isAlpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

int main()
{
	cout<< "Enter your infix expression\n";
	string exp;
	cin>> exp;
	int n = exp.size();
	cout<<"\nYour Postfix expression is ";
	for(int i=0;i<n;i++)
	{
		if(isAlpha(exp[i]))
		{
			cout<<exp[i];
			continue;
		}
		if(exp[i]==')')
		{
			while(1)
			{
				char x = pop();
				if(x == '(')
					break;
				cout<<x;
				
			}
			continue;
		}
		if(exp[i]=='(')
		{
			push(exp[i]);
			continue;
		}
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^')
		{
			while(!isEmpty() && precedence(exp[i]) <= precedence(Stack[top]))
            { 
                char c = pop(); 
                cout<<c;
            } 
            push(exp[i]); 
			continue;
		}
		
		
	}
	while(!isEmpty())
		cout<<pop();
	
}

