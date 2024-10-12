#include<iostream>
using namespace std;
int main()
{
    int arr[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,0,1,2}
    };
    int n=3,m=4;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int a[100][100];
    cout<<"enter the row and column:";
    int row,col;
    cin>>row>>col;
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }

    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}