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
bool comparator(pair<int,int> x,pair<int,int> y){
    if(x.second < y.second)
        return true;
    if(x.second > y.second)
        return false;
    
    return x < y;
    
    
    
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<pair<int,int>>>up;
        int row = 0;
        int col = 0;
        dfs(root,up,row,col);
        vector<vector<int>> ans;
        for(auto it = up.begin(); it!= up.end() ;it++){
            //cout<<it->first<<" .... "<<it->second[0]<<endl;
            sort(it->second.begin(),it->second.end(),comparator);
            vector<int>tmp;
            for(int i = 0 ; i < it->second.size();i++){
                tmp.push_back(it->second[i].first);
            }
            ans.push_back(tmp);
            
        }
        return ans;
        
    }
    void dfs(TreeNode* root,map<int,vector<pair<int,int>>> &up,int row , int col){
        
        if(root == NULL)
             return;
        
        up[col].push_back({root->val,row});
        dfs(root->left,up,row+1,col-1);
        dfs(root->right,up,row+1,col+1);
        
        
    }
};