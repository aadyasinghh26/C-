#include<iostream>
using namespace std;

bool isSafe(int i,int j,int n,int board[][10])
{
    for (int k=0;k<i;k++)   // to check the upper column
    {
        if (board[k][j]) return false;
    }

    int org_i=i , org_j=j;

    while (i>=0 and j<n)   // to check the upper right diagonal
    {
        if (board[i--][j++]==1) return false;
    }

    i=org_i; 
    j=org_j;

    while (i>=0 and j>=0)    // to check the upper left diagonal
    {
        if (board[i--][j--]==1) return false;
    }

    return true;
}

bool nQueen(int i,int n,int board[10][10])
{
    if (i==n)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                board[i][j] ? cout<<"Q" : cout<<"_";
            }
            cout<<endl;
        }
        return true;
    }

    for (int j=0;j<n;j++)    //for ith row check the columns
    {
        if (isSafe(i,j,n,board))
        {
            board[i][j]=1;
            bool kyabaakihue=nQueen(i+1,n,board);
            if (kyabaakihue) return true;
            board[i][j]=0;
        }
    }
    return false;
}

int main()
{
    int board[10][10]={0};
    int n=4;
    nQueen(0,n,board);
    return 0;
}