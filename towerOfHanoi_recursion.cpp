#include<iostream>
using namespace std;

void towerOfHanoi(int n,char source,char helper,char destination)
{
    if (n==0) return;

    towerOfHanoi(n-1,source,destination,helper);

    cout<<n<<"th disc from"<<' '<<source<<" to"<<' '<<destination<<endl;

    towerOfHanoi(n-1,helper,source,destination);
}

int main()
{
    int n;
    cout<<"enter the number of discs:";
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    return 0;
}