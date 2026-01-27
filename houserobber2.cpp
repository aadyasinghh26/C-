//leetcode question

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:

    int solve(vector<int> &nums, int s, int e)
    {
        int p = max(nums[s] , nums[s+1]);
        int ps = nums[s];

        for (int i=s+2;i<=e;i++)
        {
            int op1=nums[i]+ps;  //agar i mei chori kara
            int op2=p;         //i mei nahi chori kara

            ps=p;
            p=max(op1,op2);
        }
        return p;
    }

    int rob(vector<int>& nums)
    {
        int n=nums.size();

        if (n==1) return nums[0];
        if (n==2) return max(nums[0] , nums[1]);

        int op1=solve(nums,0,n-2);  //agar pehle ghar mei chori hogi toh last waale mei nahi hogi
        int op2=solve(nums,1,n-1);  //agar pehle waale mei chori nahi hui toh last waale mei ho sakti

        return max(op1,op2);
    }
};

int main()
{
    return 0;
}