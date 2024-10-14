#include<iostream>
using namespace std;

bool ratInmaze(int i,int j,char prob[][5],int m,int n,int sol[][10])
{
    if (i==m-1 and j==n-1)
    {
        sol[i][j]=1;
        for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<sol[i][j]<<' ';
        }
        cout<<endl;
    }
    //return true;   //to print one way
    return false;  //to print all the ways return false instead of return true
    }

    sol[i][j]=1;
    if (j+1<n and prob[i][j+1]!='X')
    {
        bool rightside=ratInmaze(i,j+1,prob,m,n,sol);
        if (rightside) return true;
    }

    if (i+1<m and prob[i+1][j]!='X')
    {
        bool fromdown=ratInmaze(i+1,j,prob,m,n,sol);
        return fromdown;
    }

    sol[i][j]=0;    //backtracking
    return false;
}

int main()
{
    char prob[][5]={
        "0000",
        "00XX",
        "0000",
        "XX00",
    };
    int sol[10][10]={0};
    ratInmaze(0,0,prob,4,4,sol);
    return 0;
}
