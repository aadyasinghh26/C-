#include<iostream>
using namespace std;
int main()
{
    int a[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row=sizeof(a)/sizeof(a[0]);
    int col=sizeof(a[0])/sizeof(int);
    cout<<"row:"<<row<<" and col:"<<col<<endl;
    int key=12;
    bool IsKeyFound=false;
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            if (a[i][j]==key)
            {
                cout<<"key found at:"<<i<<","<<j<<endl;
                IsKeyFound=true;
                break;
            }
        }
        if (IsKeyFound)
        break;
    }
    if (!IsKeyFound)
    cout<<"Key is not found"<<endl;
    return 0;
}