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
    TreeNode* deleteNode(TreeNode* root, int data) {
         if(root == NULL)
       return root;

    if(root->val == data){

        if(root->left == NULL && root->right == NULL)
            return NULL;
        if(root->left == NULL)
            return root->right;
        if(root->right == NULL)
           return root->left;
        
         TreeNode* temp = root->left;
        while(temp->right != NULL)
               temp = temp->right;

        temp->right = root->right;
        return root->left;


    }
    else if( root->val > data){
         TreeNode* temp = deleteNode(root->left,data);
        root->left = temp;
        

    }else{
         TreeNode* temp = deleteNode(root->right,data);
         root->right = temp;

    }

    return root;
    
        
    }
};