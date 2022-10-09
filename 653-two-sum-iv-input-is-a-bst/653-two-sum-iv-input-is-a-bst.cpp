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
    int maxi = INT_MIN;
    int mini = INT_MAX;
    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int,int> up;
        
        dfs(root,up);
        
        for(int i = mini ; i <= maxi ; i++){
            if(up.find(i) != up.end() ){
                up[i]--;
                if( up.find(k-i) != up.end() && up[k-i] >  0 ) 
                    return true;
                up[i]++;
            }
                
        }
        return false;
        
    }
    void dfs(TreeNode* root ,unordered_map<int,int>& up ){
        if(root == NULL){
            return;
        }
        if(up.find(root->val) != up.end()){
            up[root->val]++;
        }else{
           up[root->val] = 1;
        }
        if(root->val > maxi)
            maxi = root->val;
        if(root->val < mini)
            mini = root->val;
        
        dfs(root->left,up);
        dfs(root->right,up);
        
        
    }
};