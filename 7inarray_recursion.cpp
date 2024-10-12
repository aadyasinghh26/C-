#include<iostream>
using namespace std;

//check if 7 is present in an array
bool check7present(int *a,int n)
{
    if (n==0)
    {
        return false;
    }
    if (a[0]==7) return true;
    return check7present(a+1,n-1);
}

//first index of 7
int first7(int *a,int n)
{
    if (n==0) return -1;
    if (a[0]==7) return 0;
    int chotiProb=first7(a+1,n-1);
    if (chotiProb!=-1)
    {
        return chotiProb+1;
    }
    else
    {
        return -1;
    }
}

//last index of 7
int last7(int *a,int n,int i)
{
    if (i==n) return -1;
    if (a[i]==7)
    {
        int aageindex=last7(a,n,i+1);
        if (aageindex!=-1) return aageindex;
        else return i;
    }
    else
    {
        return last7(a,n,i+1);
    }
}

//print all indexes of 7
void printAll7(int *a,int n,int i)
{
    if (i==n) return;
    if (a[i]==7)
    {
        cout<<i<<' ';
    }
    printAll7(a,n,i+1);
}

int main()
{
    int a[]={3,2,7,1,6,7};
    int n=sizeof(a)/sizeof(int);
    if (check7present(a,n))
    {
        cout<<"present"<<endl;
    }
    else
    {
        cout<<"not present"<<endl;
    }

    cout<<"first index of 7:"<<first7(a,n)<<endl;

    int i=0;
    cout<<"last index of 7:"<<last7(a,n,i)<<endl;
    
    printAll7(a,n,i);
    return 0;
}