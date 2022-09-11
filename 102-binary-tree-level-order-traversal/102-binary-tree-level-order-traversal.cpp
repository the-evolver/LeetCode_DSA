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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>>ans;
        vector<int>curr;
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(NULL);
        
        
        while(qu.size() > 0){
            
            TreeNode* temp = qu.front();
            qu.pop();
            if(temp == NULL){
                if(qu.size() > 0){
                    qu.push(NULL);
                }
                ans.push_back(curr);
                curr.clear();
                    
                
            }
            else{
                curr.push_back(temp->val);
                if(temp->left != NULL)
                     qu.push(temp->left);
                
                if(temp->right != NULL)
                     qu.push(temp->right);
                
            }
            
        }
        return ans;
        
    }
};