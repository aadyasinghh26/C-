#include<iostream>
using namespace std;

int binarySearch(int *a,int s,int e,int key)
{
    int mid=(s+e)/2;
    if (s>e) return -1;
    if (a[mid]==key) return mid;
    else if (a[mid]<key) return binarySearch(a,mid+1,e,key);
    else return binarySearch(a,s,mid-1,key);
}

int main()
{
    int a[]={4,2,3,9,0,5,1};
    int n=sizeof(a)/sizeof(int);
    cout<<binarySearch(a,0,n-1,12);
    return 0;
}