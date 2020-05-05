#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define n 10
/***********************************
contributed by sanketpathak64
This is array implementation of stack
Implemented following functions for stack
1.push
2.pop
3.isEmpty
4.isFull
5.display
***********************************/
//struct node for stack
typedef struct stack{
	int topindex;
	int cap;
	int *arr;	
}STACK;

//initial pointer
STACK *st = (STACK *)malloc(sizeof(STACK));

//init stack
void init()
{
	st->cap = n;
	st->topindex = -1;
	st->arr =(int *) malloc(sizeof(n*sizeof(int)));
}
//function to check if array is empty
bool isEmpty()
{
	return st->topindex == -1;
}

//function to check if array is full
bool isFull()
{
	return st->topindex == n-1;
}

//function to push data into stack
void push(int data)
{
	st->arr[++st->topindex]	= data;	
}

//function to pop data from stack
int pop()
{
	
	return st->arr[st->topindex--];
}

void display()
{
	if(isEmpty())
	{
		cout<<"empty stack\n";
		return ;
	}
	cout<<"\nStack elements are as follows\n";
	for(int i=st->topindex;i>=0;i--)
		cout<<st->arr[i]<<"    ";
	cout<<endl;
}


int main()
{
	int pos,opt;
	init();
	while(1)
	{
		cout<<"\n1.push\n2.pop\n3.isempty\n4.isfull\n5.display\nenter your option  ";
		
		int option, data, pos;
		cin >> option;
		
		if(option > 5 || option < 0)
			break;
		
		switch(option)
		{
			case 1:
				cout<<"\nenter value to add ";
				cin>>data;
				if(!isFull())
					push(data);
				else
					cout<<"stack is already full\n";
				break;
				
			case 2:
				if(!isEmpty())
					pop();
				else
					cout<<"stack is already empty\n";
				break;
			
			case 3:
				cout<<isEmpty()<<"\n";
				break;
				
			case 4:
				cout<<isFull()<<"\n";
				break;
				
			case 5:
				display();
				break;				
		}	
	}
}

