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
    bool isValidBST(TreeNode* root) {
        
        // algo "" min max ka dfs krdo and then check for each nodes 
        // if curr node is bst and its left tree is bst and its right tree is bst then return true.....
        long long minm = LLONG_MIN;
        long long maxi = LLONG_MAX;
        return dfs(root,minm,maxi);
        
    }
    bool dfs(TreeNode* root,long long lo , long long hi){
         if(root == NULL )
             return true;
        
        if((root->val >= lo && root->val <= hi)
           &&(dfs(root->left,lo,(long long)root->val-1))
           &&(dfs(root->right,(long long)root->val+1,hi)))
            return true;
        
        return false;
        
    }
    
};