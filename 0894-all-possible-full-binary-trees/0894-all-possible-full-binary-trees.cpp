/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2==0)
            return {};
        vector<vector<TreeNode*>> dp(21);
        TreeNode* newNode1=new TreeNode(0);
        dp[1]={newNode1};
        TreeNode* temp1=new TreeNode(0);
        TreeNode* temp2=new TreeNode(0);
        TreeNode* newNode3=new TreeNode(0,temp1,temp2);
        dp[3]={newNode3};
        for(int i=5;i<=N;i+=2)
        {
            for(int j=1;j<i-1;j+=2)
            {
                for(auto l:dp[j])
                {
                    for(auto r:dp[i-j-1])
                    {
                        TreeNode* temp=new TreeNode(0,l,r);
                        dp[i].push_back(temp);
                    }
                }
            }
        }
        return dp[N];
    }
};