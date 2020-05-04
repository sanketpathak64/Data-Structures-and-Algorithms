#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
/***********************************
contributed by sanketpathak64
This is dynamic array implementation of stack
Implemented following functions for stack
1.push
2.pop
3.isEmpty
4.isFull
5.peek
6.display
7.function to reallocate a memory when stack is full
***********************************/

//size of stack
int n = 2;

//array for stack & index var
int top = -1;
vector<int> s(n);



//function to double size of stack
void doublestack()
{
	n = n*2;
	s.resize(n);
	cout<<"\nstack is full reallocated a memory to stack\n";
}

//function to check if stack is empty
bool isEmpty()
{
	return top == -1;
}

//function to check if stack is full
bool isFull()
{
	if(top == n-1)
		doublestack();
	return 0;
}

//function to pop a element
int pop()
{
	if(isEmpty())
	{
		cout<<"\nStack is already empty nothing to pop\n";
		return -1;
	}
	return s[top--];	
}

//function to push element in stack
void push(int data)
{
	if(isFull())
	{
		cout<<"\nThe stack is already full your value not added in stack\n";
		return ;
	}
	s[++top] = data;
}

//function to peek just get top and not removing
int peek()
{
	if(isEmpty())
	{
		cout<<"\nStack is already empty nothing to peek\n";
		return -1;	
	}
	int x = pop();
	push(x);
	return x;
}

void display()
{
	int i=top;
	do
	{
		cout<<s[i]<<"   ";
	}while(i--);
}

int main()
{
	int pos,opt;
	while(1)
	{
		cout<<"\n1.push\n2.pop\n3.peek\n4.isempty\n5.isfull\n6.display\nenter your option  ";
		
		int option, data, pos;
		cin >> option;
		
		if(option > 6 || option < 0)
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
				cout<<peek()<<endl;
				break;
			
			case 4:
				cout<<isEmpty()<<"\n";
				break;
				
			case 5:
				cout<<isFull()<<"\n";
				break;
				
			case 6:
				display();
				break;				
		}	
	}
}


