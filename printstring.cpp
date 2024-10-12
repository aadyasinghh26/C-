#include<iostream>
using namespace std;
int main()
{
    char ch;
    ch=cin.get();
    while (ch!='\n')
    {
        cout << ch;
        ch=cin.get();
    }
    cout<<endl;
    return 0;
}