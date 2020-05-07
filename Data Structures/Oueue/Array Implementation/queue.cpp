#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define n 64
/***********************************
contributed by sanketpathak64
This is array implementation of queue
***********************************/

int Queue[n],front = -1, rear = -1;

void enqueue(int data)
{
	
	if(front == -1 && rear == -1)  
    {  
        front = -1;  
        rear = 0; 
		Queue[0]=data;
		return ; 
    }  
	Queue[++rear] = data;
}

int dequeue()
{
	return Queue[front++];
}

bool isFull()
{
	return rear == n-1;
}

bool isEmpty()
{
	return  front == rear;
}

int size()
{
	return rear-front;
}
void display()
{
	if(isEmpty())
	{
		cout<<"\nEmpty Queue\n";
		return ;
	}
	cout<<"\nQueue is as follows    ";
	for(int i=front; i<=rear; i++)
		cout<<Queue[i]<<"     ";
}


int main()
{
	int pos,opt;
	while(1)
	{
		cout<<"\n1.enqueue\n2.dequeue\n3.size\n4.display\nenter your option  ";
		
		int option, data, pos;
		cin >> option;
		
		if(option > 4 || option < 0)
			break;
		
		switch(option)
		{
			case 1:
				cout<<"\nenter value to add ";
				cin>>data;
				enqueue(data);
				break;
				
			case 2:
				if(isEmpty())
				{
					cout<<"\nQueue is already empty\n";
				}
				else
					dequeue();
				break;
			
			case 3:
				cout<<"the size of queue is "<<size()<<endl;
				break;
				
			case 4:
				display();
				break;				
		}	
	}
}
