1    
11   
202  
3003 
40004

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
            if (i==1)
            {
                cout << '1';
            }
            else if (j==1 || j==i)
            {
                cout << i-1;
            }
            else
            {
                cout << '0';
            }
            j++;
        }
        int k=1;
        while (k<=n-i)
        {
            cout << ' ';
            k++;
        }
        cout << endl;
        i++;
    }
    return 0;
}

