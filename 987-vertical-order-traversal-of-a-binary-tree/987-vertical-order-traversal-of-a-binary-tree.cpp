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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
         map<int,vector<pair<int,int>>>mp;
         dfs(root,0,0,mp);
         vector<vector<int>> ans;
        
         for(auto it = mp.begin();it!= mp.end() ;it++){
               sort(it->second.begin(),it->second.end());
             vector<int>curr;
             for(int i = 0 ; i < it->second.size() ;i++){
                 curr.push_back(it->second[i].second);
             }
             ans.push_back(curr);
         }
        return ans;
        
    }
    void dfs(TreeNode* root , int row , int col , map<int,vector<pair<int,int>>>& mp){
        
        if(root == NULL)
            return;
        
        mp[col].push_back({row,root->val});
        dfs(root->left,row+1,col-1,mp);
        dfs(root->right,row+1,col+1,mp);
        
        
        
    }
};