#include<iostream>
using namespace std;
int main()
{
    int num;
    cin>>num;
    for (int n=0;n<num;n++)
    {
        int pt=1;
        cout<<pt<<' ';
        for (int r=1;r<=n;r++)
        {
            int nt=pt*(n-r+1)/r;
            cout<<nt<<' ';
            pt=nt;
        }
        cout<<endl;
    }
    return 0;
}