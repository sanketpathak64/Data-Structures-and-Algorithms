#include <iostream>
using namespace std;
void Modbubble(int a[], int n) 
{ 
   int i, j; 
   int f; 
   for (i = 0; i < n-1; i++) 
   { 
        f=0; 
        for (j = 0; j < n-i-1; j++) 
        { 
            if (a[j] > a[j+1]) 
            { 
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                f=1; 
            } 
        } 
        if (!f) //modified bubble sort
            break; 
   }
   for(i=0;i<n;i++)
        cout<<a[i]<<" ";
} 
int main() 
{
	int a[]={2,3,5,1,0,9};
	int n=6;
	Modbubble(a,n);
	return 0;
}