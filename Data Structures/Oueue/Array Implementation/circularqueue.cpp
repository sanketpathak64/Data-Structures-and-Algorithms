#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

int size = 8;
typedef struct cqueue{
	int front,rear,cap;
	int *a;
}CQ;


CQ* init()
{
	CQ *q = (CQ *)malloc(sizeof(CQ));
	q->cap = size;
	q->front = -1;
	q->rear = -1;
	q->a = (int *)malloc(size*sizeof(int));	
}

bool isEmpty(CQ *q)
{
	return q->front == -1;
}

bool isFull(CQ *q)
{
	return (q->rear + 1) % q->cap == q->front;
}

int len(CQ *q)
{
	return ( q->cap - q->front + q->rear + 1) % q->cap;
}

void enqueue(CQ *q,int data)
{
	q->rear = (q->rear + 1) % q->cap;
	q->a[q->rear] = data;
	if(q->front == -1)
		q->front = q->rear;
}

int dequeue(CQ *q)
{
	int data = q->a[q->front];
	if(q->front == q->rear)
	{
		q->front = q->rear = -1;
	}
	else
	{
		q->front = (q->front + 1) % q->cap; 
	}
	
	return data;
}

//thanks gfg for display function
void display(CQ *q)
{
	
//	cout<<"\nThe queue is as follows  ";
	if (q->front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (q->rear >= q->front) 
    { 
        for (int i =q->front; i <= q->rear; i++) 
            printf("%d ",q->a[i]); 
    } 
    else
    { 
        for (int i = q->front; i < size; i++) 
            printf("%d ", q->a[i]); 
  
        for (int i = 0; i <= q->rear; i++) 
            printf("%d ", q->a[i]); 
    } 
}


int main()
{
	CQ *queue = init();
	int pos,opt;
	while(1)
	{
		cout<<"\n1.enqueue\n2.dequeue\n3.display\nenter your option  ";
		
		int option, data, pos;
		cin >> option;
		
		if(option > 3 || option < 0)
			break;
		
		switch(option)
		{
			case 1:
				cout<<"\nenter value to add ";
				cin>>data;
				enqueue(queue,data);
//				cout<<"front "<<front<<"   rear "<<rear<<endl;
				break;
				
			case 2:
				if(isEmpty(queue))
				{
					cout<<"\nQueue is already empty\n";
				}
				else
					dequeue(queue);
					
//				cout<<"front "<<front<<"   rear "<<rear<<endl;
				break;
			
				
			case 3:
				display(queue);
				break;				
		}	
	}
}

