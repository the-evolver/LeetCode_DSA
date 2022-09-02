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
    bool isBalanced(TreeNode* root) {
        
        return dfs(root).second;
        
        
    }
    pair<int,bool> dfs(TreeNode* root){
        
        if(root == NULL)
            return {0,true};
        
        pair<int,bool> lft = dfs(root->left);
        pair<int,bool> rgt = dfs(root->right);
        
        pair<int,bool> ans;
        ans.first  = max(lft.first,rgt.first) + 1;
        ans.second = false;
       if((lft.second  == true )
                      && (rgt.second == true ) 
                      && (abs(lft.first - rgt.first) <= 1))
            ans.second = true;
        return ans;
        
        
    }
    
};