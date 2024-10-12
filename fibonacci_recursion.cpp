#include<iostream>
using namespace std;

int fibo(int n)
{
    if (n==0 || n==1)
    {
        return n;
    }
    
    int chotiProblem1=fibo(n-1);
    int chotiProblem2=fibo(n-2);
    int badiProblem=chotiProblem1 + chotiProblem2;
    return badiProblem;
}
int main()
{
    int n;
    cout<<"enter the term at which you want to find:";
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}