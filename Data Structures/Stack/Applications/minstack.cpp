#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define n 64
/***********************************
contributed by sanketpathak64
This is array implementation of stack
program to get min value in stack in O(1) by maintaining a another stack;
***********************************/

//array for stack & index var
int Stack[n], top = -1, minS[n];

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
	if(isEmpty())
	{
		top++;
		minS[top] = Stack[top] = data;
		return ;
	}
	
	int x = minS[top];
	if(x>data)
	{
		minS[++top] = data;
	}
	else
	{
		minS[++top] = x;
	}
	
	Stack[top] = data;
	
}

void minval()
{
	cout<< "minimum value in stack is " << minS[top] <<endl;
}

void display()
{
	cout<< "stack  min stack\n";
	for(int i = top;i >= 0;i--)
		cout<< Stack[i] <<"       "<< minS[i] <<endl;
}

int main()
{
	int pos,opt;
	while(1)
	{
		cout<<"\n1.push\n2.pop\n3.minval\n4.display\nenter your option  ";
		
		int option, data, pos;
		cin >> option;
		
		if(option > 4 || option < 0)
			break;
		
		switch(option)
		{
			case 1:
				cout<<"\nenter value to add ";
				cin>>data;
				push(data);
				break;
				
			case 2:
				pop();
				break;
			
			case 3:
				minval();
				break;
				
			case 4:
				display();
				break;				
		}	
	}
	
}


