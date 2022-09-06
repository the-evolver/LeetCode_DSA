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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return root;
        bool ans = dfs(root,NULL,false,false);
        if(root -> val == 0 && root->left == NULL && root->right == NULL)
            root = NULL;
        
        return root;
        
    }
    
    bool dfs(TreeNode* root,TreeNode* par,bool left , bool right){
        if(root == NULL)
            return true;
        
        bool lft = dfs(root->left,root,true,false);
        bool rgt = dfs(root->right,root,false,true);
        
        if(root->val == 0 && lft == true && rgt == true){
              //cout<<"true"<<root->val;
            if(left == true){
                par->left = NULL;
            }else if(right == true){
                par->right = NULL;
            }
             
              return true;
        }
           
         return false;
    
    }
};