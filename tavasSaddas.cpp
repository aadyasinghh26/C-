#include<iostream>
using namespace std;

int tavasSaddas(string s,int n)
{
    int count=(1<<n) - 2;  //total 1-7 digit nos. formed by 4 and 7 only

    int pos=0;
    for (int i=s.size()-1;i>=0;i--)
    {
        if (s[i] =='7')
        {
            count=count + (1<<pos);
        }
        pos++;
    }
    return count+1;
}

int main()
{
    string s1="47474747";
    int n=s1.size();
    cout<<tavasSaddas(s1,n)<<endl;

    return 0;
}