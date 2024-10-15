#include<iostream>
using namespace std;

string keys[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};


void phoneKeypad(string &ip,string &op,int i)
{
    if (i==ip.size())
    {
        cout<<op<<endl;
    }

    int digit=ip[i]-'0';
    for (int k=0;k<keys[digit].size();k++)
    {
        char ch=keys[digit][k];
        op.push_back(ch);
        phoneKeypad(ip,op,i+1);
        op.pop_back();    //backtracking
    }
}

int main()
{
    string ip="23" , op;
    phoneKeypad(ip,op,0);
    return 0;
}