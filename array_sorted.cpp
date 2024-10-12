#include<iostream>
using namespace std;

//way1
int isSorted(int *a,int n)
{
    if (n<=1)
    {
        return true;
    }
    if (a[0]<a[1] and isSorted(a+1,n-1))
        {
            return true;
        }
    else
    {
        return false;
    }
}

//way2
bool isSorted2(int *a,int n)
{
    if (n<=1)
    {
        return true;
    }
    if (a[n-1]>a[n-2] and isSorted(a,n-1))
    {
        return true;
    }
    else{
        return false;
    }
}

//way3 (with the help of iterator)
bool isSorted3(int *a,int n,int i)
{
    if (i==n-1) return true; //iterator last index par point karra toh sab sorted hee hoga
    if (a[i]<a[i+1] and isSorted3(a,n,i+1))
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int a[]={1,2,7,4,5};
    int n=sizeof(a)/sizeof(int);
    int i=0;
    if (isSorted(a,n))
    {
        cout<<"sorted"<<endl;
    }
    else
    {
        cout<<"not sorted"<<endl;
    }

    if (isSorted2(a,n))
    {
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }

    if (isSorted3(a,n,i))
    {
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
    return 0;

}