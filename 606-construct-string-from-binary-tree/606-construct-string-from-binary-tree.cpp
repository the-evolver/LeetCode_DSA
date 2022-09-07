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
    string tree2str(TreeNode* root) {
        
        stack<pair<TreeNode*,int>>st;
        string ans = "";
        st.push({root,-1});
        
        while(st.size() > 0){
            pair<TreeNode*,int> curr = st.top();
            if(curr.second == -1){
                st.top().second++;
                ans += to_string(curr.first->val);
                
            }
            else if(curr.second == 0){
                TreeNode* lft = curr.first->left;
                TreeNode* rgt = curr.first->right;
                st.top().second++;
                if(lft != NULL){
                    ans += "(";
                    st.push({lft,-1});
                }else if(rgt != NULL){
                    ans += "()";
                }
                
            }
            else if(curr.second == 1){
                TreeNode* lft = curr.first->left;
                TreeNode* rgt = curr.first->right;
                st.top().second++;
                if(lft != NULL){
                    ans += ")";
                }
                if(rgt != NULL){
                    ans += "(";
                    st.push({rgt,-1});
                }
                
                
            }
            else if(curr.second == 2){
                TreeNode* rgt = curr.first->right;
                if(rgt != NULL)
                    ans += ")";
                
                st.pop();
                
            }
        }
        return ans;
        
    }
};