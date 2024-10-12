#include<iostream>
using namespace std;

bool stairCaseSearch(int a[][4],int m,int n,int key)
{
    int i=0;
    int j=n-1;
    while (i<m and j>=0)
    {
        if (a[i][j]==key)
        {
            cout<<"key is at:"<<i<<","<<j<<endl;
            return true;
        }
        else if (a[i][j]<key)
        {
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main()
{
    int a[][4]={{1,2,3,4},{5,6,10,15},{7,11,13,16},{9,12,14,20}};
    int row=sizeof(a)/sizeof(a[0]);
    int col=sizeof(a[0])/sizeof(int);
    if (!stairCaseSearch(a,row,col,10))
    {
        cout<<"key not found"<<endl;
    }
    return 0;
}