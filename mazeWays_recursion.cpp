#include<iostream>
using namespace std;

int mazeWays(int i,int j)   //can move only right and down
{
    if (i==0 || j==0) return 1;

    return mazeWays(i-1,j) + mazeWays(i,j-1);
}

int main()
{
    cout<<mazeWays(3,3)<<endl;
    return 0;
}