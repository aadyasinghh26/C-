UNIQUE NUMBER IN A SEQUENCE

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num;
    int ans=0;
    int i=1;
    while(i<=n)
    {
        int num;
        cin>>num;
        ans^=num;
        i++;
    }
    cout << ans;
    return 0;
}