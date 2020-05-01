#include<cstdio>
#include<bits/stdc++.h>
using namespace std;




/***********************************
contributed by sanketpathak64
Implemented following functions for singly linked list
1.create node
2.add at begin and end
3.delete at begin and end
4.delete at specified position
5.display linked list
6.find max and min of linked list
7.display sum of elements of linked list
8.inserting a node at a desired position
9.reversing a linked list
10.sort the list
***********************************/




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
NODE* createNode(int data)
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
	
	if(st==NULL)
	{
		st=a;
		return;
	}
	
	while( b->next )
		b = b->next;
	b->next = a;
}

//function to display linked list
void display()
{
	if(st == NULL)
		cout<< "List is empty\n" ;
	else
	{
		cout<<"\nLinked List\n";
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

//function to delete 1st element
void delBegin()
{
	if(st == NULL)
		cout<< "List is already empty";
	else
	{
		NODE *a=st;
		st=a->next;
		free(a);
		len--;
	}
}

//function to delete last element of linked list
void delEnd()
{
	if(st == NULL)
		cout<< "List is already empty";
	else
	{
		
		if(st->next == NULL)
		{
			
			st = NULL;
			free(st);
		}
		else
		{
			NODE *a=st,*b=NULL;
			
			while(a->next != NULL)
			{
				b = a;
				a = a->next;
			}
			
			b->next = NULL;
			free(a);
			len--;	
		}
		
	}
}
//function to delete element at specified position
void delAtPos(int pos)
{
	if(pos<-1 || pos>length())
	{
		cout<< "Warning : Illegal index use 0 based Indexing";
		return ;
	}
	if(st == NULL)
		cout<< "List is already empty";
	else
	{
		if(st->next==NULL || pos==0)
		{
			delBegin();
			return ;
		}
		
		NODE *a = st,*b=NULL;
		
		while(pos--)
		{
			b = a;
			a = a->next;
		}
		
		b->next=a->next;
		len--;
	}
}


//function to find max in the linked list
void max()
{
	if(st == NULL)
	{
		cout<< "List is empty\n" ;
		return;
	}
	
	NODE *a = st;
	int max = INT_MIN;
	
	while(a)
	{
		if(a->data>max)
			max=a->data;
		a=a->next;
	}
	
	cout<<"\nMaximum element in linked list is "<<max<<endl;
}

//function to find minimum element in linked list
void min()
{
	if(st == NULL)
	{
		cout<< "List is empty\n" ;
		return;
	}
	
	NODE *a = st;
	int min = INT_MAX;
	
	while(a)
	{
		if(a->data<min)
			min=a->data;
		a=a->next;
	}
	
	cout<<"\nMinimum element in linked list is "<<min<<endl;
}

//function to display sum of elements of linked list
void sum()
{
	if(st == NULL)
		cout<<"\nList is already empty\n";
	else
	{
		NODE *a = st;
		int s = 0;
		
		while(a)
		{
			s += a->data;
			a = a->next;
		}
		
		cout<<"\nsum of all elements of linked list is "<<s<<endl;
	}
}

//function to add node at a desired position
void addPos(int data,int pos)
{
	if(pos>length() || pos<0)
	{
		cout<< "Warning : Illegal position value use 0 based indexing";
		return ;
	}
	else
	{
		if(pos==0)
		{
			addBegin(data);
			return ;
		}
		
		NODE *a = st, *b = NULL, *c=createNode(data);
		
		while(pos--)
		{
			b=a;
			a=a->next;
		}
		
		c->next = b->next;
		b->next = c;
		
		
	}
}

//function to reverse a linked list
void reverse()
{
	if(st == NULL)
	{
		cout<< "List is empty\n" ;
		return;
	}
	
	NODE *curr = st, *prev=NULL, *next=NULL;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev =curr;
		curr = next;
		curr = next;
	}
	st = prev;
	
}

//function to swap two nodes
void swap(int *a,int *b)
{
	
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//function to sort a linked list
void sort()
{
	if(st == NULL)
	{
		cout<< "List is empty\n" ;
		return;
	}
	NODE *a= st, *b = NULL;
	while(a)
	{
		b = a->next;
		while(b)
		{
			
			if(b->data < a->data)
			{
				swap(&b->data,&a->data); 
			}
			b = b->next;
			
		}
		a = a->next;
	}

}


//main function to handle linked list
int main()
{
	while(1)
	{
		cout<<"\n1.add at begin\n2.add at end\n3.delete at begin\n4.delete end\n";
		cout<<"5.delete at specified position\n6.display linked list\n7.find max\n";
		cout<<"8.find min\n9.display sum of elements of linked list";
		cout<<"\n10.inserting a node at a desired position\n11.reversing a linked list\n12.sort the list";
		cout<<"\n\nenter your option";
		
		int option, data, pos;
		cin >> option;
		
		if(option > 12 || option < 0)
			break;
		
		switch(option)
		{
			case 1:
				cout<<"\nenter value to add ";
				cin>>data;
				addBegin(data);
				break;
				
			case 2:
				cout<<"\nenter value to add ";
				cin>>data;
				addEnd(data);
				break;
			
			case 3:
				delBegin();
				break;
			
			case 4:
				delEnd();
				break;
				
			case 5:
				cout<<"\nenter position of element use 0 based indexing";
				cin>>pos;
				delAtPos(pos);
				break;
			
			case 6:
				display();
				break;
			
			case 7:
				max();
				break;
			
			case 8:
				min();
				break;
			
			case 9:
				sum();
				break;
				
			case 10:
				cout<<"\nenter data ";
				cin>>data;
				cout<<"\nenter position use 0 based indexing ";
				cin>>pos;
				addPos(data, pos);
				break;
				
			case 11:
				reverse();
				break;
				
			case 12:
				sort();
				break;
				
		}	
	}
}
