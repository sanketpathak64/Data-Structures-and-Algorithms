#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/626005/C%2B%2B-Binary-Search-O(logn)
int Search(vector<int> vec,int target)
{
    int start = 0,end = vec.size()-1;
    if(!vec.size())
        return -1;
    int mid;
    while(start<=end)
    {
        mid = (start + end)/2;
        if(vec[mid]==target)
            return mid;
        if(vec[mid]>=vec[start])//first part sorted
        {
            if(target<=vec[mid] && target>=vec[start])
            {
                end=mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        else
        {
            if(vec[end] >= vec[mid]){
                if(target>=vec[mid] && target<=vec[end])
                {
                    start=mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
    }
    return -1;
}


int main()
{
	vector<int> a(5);
	a[0]=3;
	a[1]=4;
	a[2]=5;
	a[3]=1;
	a[4]=2;
	cout<<Search(a,4);
	
}
