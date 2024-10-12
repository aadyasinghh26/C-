#include<iostream>
using namespace std;
int main()
{
    char ch;
    ch=cin.get();
    int x=0,y=0;
    while (ch!='\n')
    {
        if (ch=='N')
        y++;
        else if (ch=='S')
        y--;
        else if (ch=='E')
        x++;
        else if (ch=='W')
        x--;
        ch=cin.get();
    }
    if (x>0)
    {
        for (int i=1;i<=x;i++)
        {
            cout << 'E';
        }
    }
    if (y>0)
    {
        for (int i=1;i<=y;i++)
        {
            cout << 'N';
        }
    }
    else
    {
        y=y*(-1);
        for (int i=1;i<=y;i++)
        {
            cout << 'S';
        }
    }
    if (x<0)
    {
        x=x*(-1);
        for (int i=1;i<=x;i++)
        {
            cout << 'W';
        }
    }
    return 0;
}