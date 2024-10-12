*******
*** ***
**   **
*     *
**   **
*** ***
*******

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while (i<=n)
    {
        if (i==1)
        {
            int j=1;
            while(j<=(2*n)-1)
            {
                cout << '*';
                j=j+1;
            }
        }
        else
        {
            int k=1;
            while (k<=(n+1)-i)
            {
                cout << '*';
                k=k+1;
            }
            int l=1;
            while (l<=(2*i)-3)
            {
                cout << ' ';
                l=l+1;
            }
            int m=1;
            while (m<=(n+1)-i)
            {
                cout << '*';
                m=m+1;
            }
        }
        cout<<endl;
        i=i+1;
    }
    i=n-1;
    while (i>=1)
    {
        if (i==1)
        {
            int j=1;
            while(j<=(2*n)-1)
            {
                cout << '*';
                j=j+1;
            }
        }
        else
        {
            int k=1;
            while (k<=(n+1)-i)
            {
                cout << '*';
                k=k+1;
            }
            int l=1;
            while (l<=(2*i)-3)
            {
                cout << ' ';
                l=l+1;
            }
            int m=1;
            while (m<=(n+1)-i)
            {
                cout << '*';
                m=m+1;
            }
        }
        cout<<endl;
        i=i-1;
    }
    return 0;
}