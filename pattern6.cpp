1    
22   
303  
4004 
50005

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=i;
        int l=1;
        while (l<=j)
        {
            if (l==1 || l==j)
            {
                cout << j;
            }
            else
            {
                cout << '0';
            }
            l=l+1;
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