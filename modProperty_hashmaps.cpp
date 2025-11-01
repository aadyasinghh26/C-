#include<iostream>
using namespace std;

int main()
{
    string key="AADYA SINGH";

    int ans=0;
    int mul=1;

    for (int i=0;i<key.size();i++)
    {
        ans+=(key[i] % 7) * mul % 7;
        mul*=37;
        ans%=7;
        mul%=7;
    }
    ans%=7;

    cout<<ans<<endl;

    return 0;
}
