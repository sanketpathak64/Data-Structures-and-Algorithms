/******************
code taken from GFG and modified a little
******************/

//code not working

// CPP program for array implementation of queue 
#include <bits/stdc++.h> 
using namespace std; 

// A structure to represent a queue 
class Queue 
{ 
	public: 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 

// function to create a queue of given capacity. 
// It initializes size of queue as 0 
Queue* createQueue(unsigned capacity) 
{ 
	Queue* queue = new Queue(); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 
	queue->rear = capacity - 1; // This is important, see the enqueue 
	queue->array = new int[(queue->capacity * sizeof(int))]; 
	return queue; 
} 

// Queue is full when size 
// becomes equal to the capacity 
int isFull(Queue* queue) 
{ return (queue->size == queue->capacity); } 

// Queue is empty when size is 0 
int isEmpty(Queue* queue) 
{ return (queue->size == 0); } 

// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(Queue* queue, int item) 
{ 
	if (isFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) % queue->capacity; 
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	cout << item << " enqueued to queue\n"; 
} 

// Function to remove an item from queue. 
// It changes front and size 
int dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) % queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
} 

// Function to get front of queue 
int front(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
} 

// Function to get rear of queue 
int rear(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
} 


void display(Queue* queue)
{
	if(isEmpty(queue))
	{
		cout<<"\nEmpty Queue\n";
		return ;
	}
	cout<<"\nQueue is as follows    ";
	for(int i=front(queue); i<=rear(queue); i++)
	{
		cout<<queue->array[i]<<"     ";
		if(front(queue) == queue->capacity-1)
			queue->front = 0;
		if(rear(queue) == queue->capacity-1)
			queue->rear = 0;
	}
}

int main()
{
	Queue* queue = createQueue(1000); 
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

