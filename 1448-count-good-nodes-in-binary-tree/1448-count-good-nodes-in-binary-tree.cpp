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
    int goodNodes(TreeNode* root) {
        
        return dfs(root,INT_MIN);
        
    }
    
    int dfs(TreeNode* root , int maxx){
        if(root == NULL)
            return 0;
        
        int ans = 0; // ans calculation 
        
        if( root->val >= maxx){ // checking if current node satisfies the condition 
            ans++;
            maxx = root->val;   // updating maxx
        }
        
         ans += dfs(root->left,maxx);  // now for complete ans for root we need to get both left and right part answers..
         ans += dfs(root->right,maxx);
        
         return ans;
    }
};