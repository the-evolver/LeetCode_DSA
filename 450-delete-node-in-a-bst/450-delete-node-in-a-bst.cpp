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
    TreeNode* tmp;
    TreeNode* deleteNode(TreeNode* root, int key) { 
        
        // 3 cases : node with 2 child -- 1 child -- 0 child
        return dfs(root,key);
        
        
        
    }
    
    TreeNode* dfs(TreeNode* root, int key){
        if(root == NULL)
            return root;
        if(root->val == key){
            if(root->left == NULL)
                return root->right;
            if(root->right == NULL)
                return root->left;
            
            
            tmp->right = best_Replacement(root->right);
            tmp->left  = root->left;
           
            return tmp;
            
        }
        else if(root->val > key){
            TreeNode* temp = dfs(root->left,key);
            root->left = temp;
        }
        else if(root->val < key){
            TreeNode* temp = dfs(root->right,key);
            root->right = temp;
            
        }
        
        
        
        return root;
        
        
    }
    TreeNode* best_Replacement(TreeNode* root){
          
        if(root->left == NULL){
             tmp = root;
            // tmp->left  = NULL;
            // tmp->right = NULL;
            return root->right;
        }
            
        
        TreeNode* temp = best_Replacement(root->left);
        root->left = temp;
        return root;
        
        
        
    }
};