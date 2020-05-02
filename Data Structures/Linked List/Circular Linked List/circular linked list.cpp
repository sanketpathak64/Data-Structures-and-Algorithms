#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

/***********************************
contributed by sanketpathak64
1.add at begin/end
2.del begin/last
3.display
***********************************/

//node for circular linked list
typedef struct Node 
{ 
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

//function to find length of linked list
int length()
{	
	return len;
}

//function to add node at baginning of circular linked list
void addBegin(int data)
{
	NODE *a = createNode(data);
	
	if(st == NULL)
	{
		a->next = a;
		st = a;
	}
	else
	{
		a->next = st->next;
		st->next = a;
	}
}

//function to add node at end of circular linked list
void addEnd(int data)
{
	NODE *a = createNode(data);
	
	if(st == NULL)
	{
		a->next = a;
		st = a;
	}
	else
	{
		a->next = st->next;
        st->next = a;
        st = a;
	}
}


//function to display circular linked list
void display()
{
	if(st == NULL)
	{
		cout<< "CLL is empty";
		return ;
	}
		
	NODE *a = st->next;
	
	while(1)
	{
		cout<< a->data << "-> " ;
		a = a->next;
		
		if(a == st)
			break;
	}
	if(len!=1)  //temporary fix
		cout<< a->data << endl;
	
	
}

//function to delete beginning of CLL
void delFirst()
{
    NODE *a = NULL;
    if(st == NULL)
        return;
        
    if(st->next == st)
    {
        free(st);
        st = NULL;
        len--;
        return;
    }
    
    a = st->next;
    st->next = a->next;
    free(a);
    len--;
} 

//fn to delete last node
void delLast()
{
    NODE *a = NULL;
    if(st == NULL)
        return;;
    if(st->next == st)
    {
        free(st);
        st = NULL;
        len--;
        return;
    }
    a = st->next;
    while(a->next != st)
        a = a->next;
    a->next = st->next;
    free(st);
    len--;
    st=a;
}


int main()
{
    int  a;
    int opt;
    while(1)
    {
        cout<<"\n1.add node at beginning\n2.add node at end\n3.delete first node\n4.display\n5.delete last node";
        cin>>opt;
        if(opt > 6)
            break;
            
        switch(opt)
        {
	        case 1:
	            cout<< "enter data";
	            cin>> a;
	            addBegin(a);
	            break;
	            
	        case 2:
	            cout<<"enter data";
	            cin>> a;
	            addEnd(a);
	            break;
	            
	        case 3:
	            delFirst();
	            break;
	            
	        case 4:
	            display();
	            break;
	            
	        case 5:
	            delLast();
	            break;

        }
    }
    return 0;
}
