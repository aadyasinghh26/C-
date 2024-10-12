* **** **** *
** *** *** **
*** ** ** ***
**** * * ****

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while (i<=n)
    {
        int j=1;
        while (j<=i)
        {
            cout << '*';
            j=j+1;
        }
        cout << ' ';
        int k=1;
        while (k<=(n-i)+1)
        {
            cout << '*';
            k=k+1;
        }
        cout << ' ';
        int l=1;
        while (l<=(n-i)+1)
        {
            cout << '*';
            l=l+1;
        }
        cout << ' ';
        int m=1;
        while (m<=i)
        {
            cout << '*';
            m=m+1;
        }
        cout << endl;
        i=i+1;
    }
    return 0;
}