#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

//linked list node 
typedef struct Node { 
    int data; 
	struct Node* next; 
} NODE;

//variable maintaining length of linked list
int len=0;

//setting start to null
NODE *st = NULL;

//function to create node
NODE *createNode(int data)
{
    NODE *a = (NODE *)malloc(sizeof(NODE));
    a->data = data;
    a->next = NULL;
    len++;
    return a;
}

//function to add node at beginning
void addBegin(int data)
{
	NODE *a = createNode(data);
	a->next=st;
	st=a;		
}

//function to add node at end
void addEnd(int data)
{
	NODE *a = createNode(data);
	NODE *b = st;
	while( b->next )
		b = b->next;
	b->next = a;
}

//function to display linked list
void display()
{
	if(st == NULL)
		cout<< "List is empty" ;
	else
	{
		NODE *a = st;
		while(1)
		{
			if(a == NULL)
				break;
			cout<< a->data << "  ->  ";
			a = a->next;
		}
	}
}

//function to find length of linked list
int length()
{
	
	return len;
}




//main function to handle linked list
int main()
{
	addBegin(6);
	addBegin(5);
	addBegin(4);
	addBegin(3);
	addEnd(7);
	addBegin(3);
	addEnd(1000);
	display();
	cout<<length();
	
}
