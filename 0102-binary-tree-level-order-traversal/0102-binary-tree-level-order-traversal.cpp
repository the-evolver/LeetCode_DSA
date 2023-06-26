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
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.empty() == false){
            int sz = q.size();
            vector<int> level;
            for(int i = 0 ; i < sz ; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};