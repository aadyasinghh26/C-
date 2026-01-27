//leetcode question

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:

    vector <int> ans;

    void solve(TreeNode *root, int &minD, int d=0)
    {
        //base case
        if (!root) return;

        if (d>minD)
        {
            minD=d;
            ans.push_back(root->val);
        }

        solve(root->right,minD,d+1);
        solve(root->left,minD,d+1);
    }

    vector<int> rightSideView(TreeNode* root)
    {
        int minD=-1;

        solve(root,minD);
        return ans;
    }
};

int main()
{
    return 0;
}