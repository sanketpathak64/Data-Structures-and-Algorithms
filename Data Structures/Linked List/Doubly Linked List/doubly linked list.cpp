#include<cstdio>
#include<bits/stdc++.h>
using namespace std;


/***********************************
contributed by sanketpathak64
Implemented following functions for doubly linked list
1.add node at beginning and end
2.add node at specified pos //little issue
3.delete from start and end 
4.delete at specified position //little issue
5.display list from start to end and vice a versa
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

//function to delete a element at specified pos
void delPos(int pos) //same issue as in insertAt deletes +1 place
{
	NODE *a = st;
	if(pos>length() || pos<0)
	{
		cout<<"invalid pos\n";
		return ;
	}
	while(pos--)
		a = a->next;
	
	NODE *b = a;
	b->next = a->next->next;
	b->next->prev = a;
}

int main()
{
	int pos,opt;
	while(1)
	{
		cout<<"\n1.add at begin\n2.add at end\n3.delete at begin\n4.delete end\n";
		cout<<"5.delete at specified position\n6.display DLL from start to end\n7.display DLL from end to start";
		cout<<"\n8.inserting a node at a desired position\n";
		cout<<"\n\nenter your option";
		
		int option, data, pos;
		cin >> option;
		
		if(option > 8 || option < 0)
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
				delFirst();
				break;
			
			case 4:
				delLast();
				break;
				
			case 5:
				cout<<"\nenter position of element use 0 based indexing";
				cin>>pos;
				delPos(pos);
				break;
			
			case 6:
				dSE();
				break;
			
			case 7:
				dES();
				break;
				
			case 8:
				cout<<"\nenter data ";
				cin>>data;
				cout<<"\nenter position use 0 based indexing ";
				cin>>pos;
				insertAt(data, pos);
				break;
				
				
		}	
	}
}
