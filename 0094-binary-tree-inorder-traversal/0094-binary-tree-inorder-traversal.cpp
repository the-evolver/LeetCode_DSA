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
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> arr;
        inor(root,arr);
        return arr;
        
    }
    void inor(TreeNode* root,vector<int>& arr){
        if(root == NULL)
            return ;
        
        
        inor(root->left,arr);
        arr.push_back(root->val);
        inor(root->right,arr);
        
    }
};