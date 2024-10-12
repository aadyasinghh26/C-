#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cout<<"enter the number:";
    cin>>n1>>n2;
    int nterms=0;
    for (int i=1;nterms!=n1;++i)
    {
        int term=(3*i)+2;
        if (term%n2!=0)
        {
            cout<<term<<' ';
            nterms++;
        }
    }
    return 0;
}