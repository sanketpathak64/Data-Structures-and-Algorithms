#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define n 4
/***********************************
contributed by sanketpathak64
This is second array implementation of queue
In previous code there was wastage of space after dequeue operation
***********************************/

int Queue[n],front = -1, rear = -1;

//function to add element at back
void enqueue(int data)
{
	
	if(front == -1 && rear == -1)  
    {  
        front = -1;  
        rear = 0; 
		Queue[0]=data;
		return ; 
    }  
    rear = (rear+1)%n;
	Queue[rear] = data;
}

//function to remove element from front
int dequeue()
{
	int x =Queue[front];
	front = (front+1)%n;
	return x;
}

bool isFull()
{
	return rear == n-1;
}

bool isEmpty()
{
	return  front == rear;
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
	{
		cout<<Queue[i]<<"     ";
		if(front == n-1)
			front = 0;
		if(rear == n-1)
			rear = 0;
	}
}


int main()
{
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
				enqueue(data);
				cout<<"front "<<front<<"   rear "<<rear<<endl;
				break;
				
			case 2:
				if(isEmpty())
				{
					cout<<"\nQueue is already empty\n";
				}
				else
					dequeue();
					
				cout<<"front "<<front<<"   rear "<<rear<<endl;
				break;
			
				
			case 3:
				display();
				break;				
		}	
	}
}
