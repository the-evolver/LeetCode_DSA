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
        
        // iterative soln;
        if(root == NULL)
            return {};
        
        stack<pair<TreeNode*,int>>st;
        st.push({root,-1});
        vector<int>ans;
        
        while(st.size() > 0){
            int curr = st.top().second;
            TreeNode* tmp = st.top().first;
            
            if(curr == -1 ){
                st.top().second++;
                
            }else if(curr == 0){
                st.top().second++;
                if(tmp->left != NULL){
                    st.push({tmp->left,-1});
                   
                }
                 
            }else if(curr == 1){
                ans.push_back(tmp->val);
                st.top().second++;
                if(tmp->right != NULL)
                    st.push({tmp->right,-1});
                
                
            }else if(curr == 2){
                st.pop();
                
            }
            
        }
        return ans;
        
    }
};