#include<iostream>
using namespace std;

void printpairs(int a[],int n,int sum)
{
    for (int i=0;i<n;i++)
    {
       int no1=a[i];
       int no2=sum-a[i];
       for (int j=i+1;j<n;j++)
       {
           if (a[j]==no2)
           {
               cout<<"("<<no1<<","<<no2<<")"<<endl;
           }
       }
    
    }
}

int main()
{
    int a[]={1,2,4,6,8,9,0};
    int n=sizeof(a) / sizeof(int);
    printpairs(a,n,10);
    return 0;
}