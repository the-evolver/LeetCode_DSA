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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        pr(root,arr);
        return arr;
    }
    void pr(TreeNode* root,vector<int>& arr){
        if(root == NULL)
            return;
        
        arr.push_back(root->val);
        pr(root->left,arr);
        pr(root->right,arr);
        
        return;
    }
};