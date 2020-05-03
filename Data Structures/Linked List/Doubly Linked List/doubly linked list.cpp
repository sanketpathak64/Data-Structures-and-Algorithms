#include<cstdio>
#include<bits/stdc++.h>
using namespace std;


/***********************************
contributed by sanketpathak64
Implemented following functions for doubly linked list

***********************************/

//Node for doubly linked list
typedef struct node   
{  
    struct node *prev;   
    int data;  
    struct node *next;   
}NODE;

//var to maintain node count
int len = 0;

//function to create a node
NODE* createNode(int data)
{
    NODE *a = (NODE *)malloc(sizeof(NODE));
    a->data = data;
    a->next = NULL;
    a->prev = NULL;
	len++;
    return a;
}

//starting pointer for doubly linked list
NODE *st = NULL;   

//ending pointer for doubly linked list
NODE *ed = createNode(0);

//function to return length of DLL
int length()
{
	return len;
}
//function to add node at beginning
void addBegin(int data)
{
	NODE *a = createNode(data);
	
	if(st == NULL)
	{
		st = a;
		ed->prev = st;
	}
	else
	{
		a->next = st;
		st->prev = a;
		st = a;
	}
}

//function to add node at end
void addEnd(int data)
{
	NODE *a = createNode(data);
	NODE *b = st;
	if(st == NULL)
	{
		st = a;
		ed->prev = a;
	}
	else
	{
		while(b->next != NULL)
			b = b->next;
		
		a->prev = b;
		b->next = a;
		ed->prev = a;
	}
}



//function to display DLL from beginnning
void dSE()  
{  
	if(st == NULL)
		cout<<"DLL SE is empty\n";
    NODE *a = st;  
    cout<<"\n DLL from S to E\n";  
      
    while(a != NULL)  
    {  
        cout<< a->data << "-> ";  
        a = a->next;  
    }  
    cout<<endl;
}

//function to display DLL from end
void dES()  
{
	if(ed == NULL)
		cout<<"DLL ES is empty\n";  
    NODE *a = ed->prev;  
    cout<<"\n DLL from E to S\n";  
      
    while(a != NULL)  
    {  
        cout<< a->data << "-> ";  
        a = a->prev;  
    }  
    cout<<endl;
} 

//function to delete the first element
void delFirst()
{
	if(st == NULL)
		cout<<"DLL is empty\n";
	
	NODE *a = st;
	if(a->next == NULL)
	{
		st = NULL;
		free(st);
		ed = NULL;
		len--;
	}
	else
	{
		st = st->next;
		st->prev = NULL;
		free(a);
		len--;
	}
}

//function to delete last element
void delLast()
{
	if(st == NULL)
	{
		cout<<"DLL is empty\n";
		return ;
	}
	NODE *a = ed;
	NODE *b = st;
	if(b->next == NULL)
	{
		cout<<"in1";
		st = NULL;
		free(st);
		ed = NULL;
		free(ed);
		len--;
		return ;
	}
	ed = ed->prev;
	free(a);
	ed->prev->next = NULL;
	len--;
	
}

//function to insert data at specified position
void insertAt(int data,int pos) //not working properly inserts element at +1 place
{
	NODE *a = st;
	NODE *b = createNode(data);
	if(pos<-1 || pos>length())
	{
		cout<<"invalid pos\n";
		return ;
	}
	
	while(pos--)
		a = a->next;
	b->next = a->next;
	b->prev = a;
	a->next = b;
	a->next->prev = b;
}

int main()
{
	addBegin(4);
	addEnd(6);
	addBegin(3);
	addBegin(2);
	addBegin(1);
	dSE();
	dES();
	insertAt(100,0);
	dSE();
}
