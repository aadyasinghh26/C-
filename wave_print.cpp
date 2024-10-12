#include<iostream>
using namespace std;
int main()
{
    int a[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(a[0])/sizeof(int);
    for (int col=0;col<n;col++)
    {
        if (col%2==0)
        {
            for (int row=0;row<m;row++)
            {
                cout<<a[row][col]<<' ';
            }
        }
        else
        {
            for (int row=m-1;row>=0;row--)
            {
                cout<<a[row][col]<<' ';
            }
        }
    }
    return 0;
}