#include<iostream>
using namespace std;
int main()
{
    int rows , columns;
    cout<<"enter the row and column:";
    cin>>rows>>columns;
    int **arr=new int*[rows];
    
    for (int i=0;i<rows;i++)
    {
        arr[i]=new int[columns];
    }

    int number=1;
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<columns;j++)
        {
            arr[i][j]=number++;
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }

    //to delete the array
    for (int i=0;i<rows;i++)
    {
            delete [] arr[i];
    }
    delete [] arr;
    return 0;
}