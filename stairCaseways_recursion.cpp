#include<iostream>
using namespace std;

int stairCaseways(int n)
{
   if (n==0) return 1;
   if (n<0)  return 0;

   return stairCaseways(n-1)+stairCaseways(n-2)+stairCaseways(n-3); 
}

int nstairs(int n,int k)
{
    if (n==0) return 1;
    if (n<0)  return 0;
    
    int ans=0;
    for (int i=1;i<=k;i++)
    {
        ans+=nstairs(n-i,k);
    }
    return ans;
}

int main()
{
    cout<<"first:"<<stairCaseways(4)<<endl;
    cout<<"second:"<<nstairs(4,3)<<endl;
    return 0;
}