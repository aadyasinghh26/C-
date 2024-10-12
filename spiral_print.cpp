#include<iostream>
using namespace std;

void SpiralPrint(int a[][4],int m,int n)
{
    int sr=0,sc=0;
    int er=m-1;
    int ec=n-1;
    while (sr<=er and sc<=ec)
    {
        for (int col=sc;col<=ec;col++)
        {
            cout<<a[sr][col]<<' ';
        }
        sr++;
        
        for (int row=sr;row<=er;row++)
        {
            cout<<a[row][ec]<<' ';
        }
        ec--;

        if (sc<=ec)
        {
            for (int col=ec;col>=sc;col--)
            {
            cout<<a[er][col]<<' ';
            }
        er--;
        }

        if (sr<=er)
        {
            for (int row=er;row>=sr;row--)
        {
            cout<<a[row][sc]<<' ';
        }
        sc++;
        }
    }

}
int main()
{
    int a[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int row=sizeof(a)/sizeof(a[0]);
    int col=sizeof(a[0])/sizeof(int);
    SpiralPrint(a,row,col);
    return 0;
}