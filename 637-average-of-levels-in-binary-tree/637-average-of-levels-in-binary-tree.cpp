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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*>qu;
        qu.push(root);
        qu.push(NULL);
        vector<double> ans;
        double curr = 0;
        int cnt = 0;
        while(qu.empty() == false){
            TreeNode* temp = qu.front();
            qu.pop();
            if(temp == NULL){
                if(qu.size() != 0){
                    qu.push(NULL);
                }
                ans.push_back(curr/cnt);
                curr = 0;
                cnt = 0;
                
                
            }else{
                curr += temp->val;
                cnt++;
                if(temp->left != NULL)
                    qu.push(temp->left);
                if(temp->right != NULL)
                    qu.push(temp->right);
            
            
            }
        }
        
        return ans;
    }
};