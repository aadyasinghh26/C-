#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"enter the characters:";
    cin>>ch;

    int count = 0;
    while(ch!= '$')
    {
        count++;
        cin>>ch;
    }
    cout<<count<<endl;
    return 0;

}