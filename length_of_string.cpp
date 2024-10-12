#include<iostream>
using namespace std;

int lengthofstring(char*a)
{
    int i;
    for (i=0;a[i]!='\0';i++)
    { }
    return i;
}
int main()
{
    char arr[100];
    cin.getline(arr,100);
    int len=lengthofstring(arr);
    cout<<"length is:"<<len<<endl;
    return 0;
}