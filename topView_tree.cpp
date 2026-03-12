#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};

TreeNode* buildTree(vector<int>& nodes)
{
    if(nodes.size() == 0 || nodes[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < nodes.size())
    {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if(nodes[i] != -1)
        {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if(i >= nodes.size()) break;

        // right child
        if(nodes[i] != -1)
        {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void topView(TreeNode *root)
{
    if (!root) return;

    map<int,int> mpp;
    queue<pair<TreeNode* , int> > q;
    q.push({root,0});

    while (!q.empty())
    {
        auto p=q.front();
        q.pop();

        TreeNode *node=p.first;
        int line=p.second;
        

        if (mpp.find(line) == mpp.end())
        {
            mpp[line]=node->val;
        }

        if (node->left) q.push({node->left,line-1});
        if (node->right) q.push({node->right,line+1});
    }

        for (auto &p : mpp)
        {
            cout<<p.second<<" ";
        }
        cout<<endl;
    
}

int main()
{
    int n;
    cin >> n;

    vector<int> nodes(n);
    for(int i=0;i<n;i++)
        cin >> nodes[i];

    TreeNode* root = buildTree(nodes);
    topView(root);

    return 0;
}