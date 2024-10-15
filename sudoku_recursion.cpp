#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int i,int j,int n,int mat[9][9],int number)
{
    for (int k=0;k<n;k++)
    {
        if (mat[i][k]==number || mat[k][j]==number) return false;    //checking row and column
    }

    n=sqrt(n);       // checking each box
    int si= (i/n)*n;
    int sj= (j/n)*n;
    for (i=si;i<si+n;i++)
    {
        for (j=sj;j<sj+n;j++)
        {
            if (mat[i][j]==number) return false;
        }
    }
    return true;             // we can put the number
}

bool solveSudoku(int i,int j,int n,int mat[9][9])
{
    if (i==n)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<' ';
            }
            cout<<endl;
        }
        return true;
    }

    if (j==n)    //move to next row
    return solveSudoku(i+1,0,n,mat);

    if (mat[i][j]!=0)   //if the box is already filled
    return solveSudoku(i,j+1,n,mat);

    for (int number=1;number<=n;number++)
    {
       if (isSafe(i,j,n,mat,number))
       {
        mat[i][j]=number;
        bool baakihue=solveSudoku(i,j+1,n,mat);
        if (baakihue) return true;
        mat[i][j]=0;   //backtracking
       } 
    }
    return false;
}

int main()
{
    int mat[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    int n=9;
    solveSudoku(0,0,n,mat);
}