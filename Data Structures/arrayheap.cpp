#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
//wrong
typedef struct heap
{
	int *array;
	int count;
	int size;
	bool type; //1 for max, 0 for min
}HEAP;

HEAP *createHeap(int size,bool type)
{
	HEAP *a = (HEAP *)malloc(sizeof(struct heap));
	a->array = (int *)malloc(sizeof(int)*size);
	a->count = 0;
	a->size = size;
	a->type = type;
	
	return a;
}

int parent(HEAP *a,int i) //takes child index and returns parent
{
	if(i<=0 || i>=a->count)
		return -1;
	return (i-1)/2;
}

int lchild(HEAP *a,int i)
{
	int lc = i*2+1;
	if(lc>=a->count)
		return -1;
	return lc;
}


int rchild(HEAP *a,int i)
{
	int rc = i*2+2;
	if(rc>=a->count)
		return -1;
	return rc;
}

//void heapify(HEAP *a, int i) 
//{ 
//    int largest = i; // Initialize largest as root 
//    int l = 2 * i + 1; // left = 2*i + 1 
//    int r = 2 * i + 2; // right = 2*i + 2 
//  
//    // If left child is larger than root 
//    if (l < n && arr[l] > arr[largest]) 
//        largest = l; 
//  
//    // If right child is larger than largest so far 
//    if (r < n && arr[r] > arr[largest]) 
//        largest = r; 
//  
//    // If largest is not root 
//    if (largest != i) { 
//        swap(arr[i], arr[largest]); 
//  
//        // Recursively heapify the affected sub-tree 
//        heapify(arr, n, largest); 
//    } 
//} 


void percolatedown(HEAP *b,int i)
{
	HEAP *a=b;
	int l,r,max,temp;
	l = lchild(a,i);
	r = rchild(a,i);
	
	if(l!=-1 && a->array[l] > a->array[i])
		max = l;
	else
		max = i;
		
	if(r!=-1 && a->array[r] > a->array[max])
		max = r;
	if(max != i)
	{
		temp = a->array[i];
		a->array[i] = a->array[max];
		a->array[max] = temp;
	}
	percolatedown(a,max);
}
void add(HEAP *a,int data)
{
	
	int i=++a->count;
	while(i>=0 && data > a->array[(i-1)/2])
	{
		a->array[i] = a->array[(i-1)/2];
		i=(i-1)/2;
		
	}
	a->array[i] = data;
}

//void buildHeap(int arr[], int n) 
//{ 
//    // Index of last non-leaf node 
//    int startIdx = (n / 2) - 1; 
//  
//    // Perform reverse level order traversal 
//    // from last non-leaf node and heapify 
//    // each node 
//    for (int i = startIdx; i >= 0; i--) { 
//        heapify(arr, n, i); 
//    } 
//} 




int main()
{
	HEAP *h = createHeap(8,1);
	cout<<"hello";
	add(h,4);
	add(h,3);
	add(h,7);
	add(h,2);
	 cout<<"hello";
	
	for(int i=1;i<=h->count;i++)
		cout<<h->array[i]<<" ";
	cout<<endl;
//	for(int i=1;i<=1;i++)
	percolatedown(h,0);
	for(int i=1;i<=h->count;i++)
		cout<<h->array[i]<<" ";
}
