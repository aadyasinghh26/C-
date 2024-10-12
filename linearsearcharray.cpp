#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number: ";
    cin>>n;
    int a[1000];
    int i=0;
    while (i<n)
    {
        cin>>a[i];
        i++;
    }
    int num;
    cout << "enter the number you want to search: ";
    cin>>num;
    int index=-1;
    for (int i=0;i<n;i++)
    {
        if (a[i]==num)
        {
            index=i;
            break;
        }
    }
    cout<<"the"<<' '<<num<<' '<<"is present at index:"<<index;
    return 0;
}