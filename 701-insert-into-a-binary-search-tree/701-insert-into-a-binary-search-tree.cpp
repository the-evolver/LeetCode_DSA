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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        
        if(root->val > val){
            TreeNode* temp =  insertIntoBST(root->left,val);
            root->left = temp;
        }else{
             TreeNode* temp = insertIntoBST(root->right,val);
             root->right = temp;
        }
            
        
       return root;
        
    }
};