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

//function to add node at beginning

void addBegin(int data)
{
	NODE *a = createNode(data);
	
	if(st == NULL)
	{
		st = a;
	}
	else
	{
		a->next = st;
		st->prev = a;
		st = a;
	}
}





//function to display DLL from beginnning
void dSE()  
{  
    NODE *a = st;  
    printf("\n DLL from S to E\n");  
      
    while(a != NULL)  
    {  
        cout<<a->data<<"-> ";  
        ptr=ptr->next;  
    }  
    cout<<endl;
} 



int main()
{
	addBegin(4);
	addBegin(3);
	addBegin(2);
	addBegin(1);
	dSE();
}
