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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int cdepth = depth;
        if(depth == 1){
            TreeNode* nn = new TreeNode(val,root,NULL);
            return nn;
        }
            
        queue<pair<TreeNode*,TreeNode*>>qu;
        qu.push({root,NULL});
        qu.push({NULL,NULL});
        depth--;
        
        while(qu.size() > 0 && depth >= 0){
            pair<TreeNode*,TreeNode*> tp = qu.front();
            qu.pop();
            
            if(tp.first == NULL){
                if(qu.size() > 0)
                     qu.push({NULL,NULL});
                
                depth--;
            }else{
                
                if(depth == 0){
                TreeNode* ch = tp.first;
                TreeNode* par = tp.second;
                if(par->left == ch){
                    TreeNode* nn = new TreeNode(val,ch,NULL);
                    par->left = nn;
                    
                }else{
                    TreeNode* nn = new TreeNode(val,NULL,ch);
                    par->right = nn;
                    
                }
                    if(par->left == NULL)
                    par->left = new TreeNode(val,NULL,NULL);
                    if(par->right == NULL)
                    par->right = new TreeNode(val,NULL,NULL);
                
                
            }
            else if(depth == 1 && tp.first->left == NULL && tp.first->right == NULL){
                TreeNode* ch = tp.first;
                ch->left = new TreeNode(val);
                ch->right = new TreeNode(val);
                
            }
            else{
                
                TreeNode* t = tp.first;
                if(t->left != NULL)
                    qu.push({t->left,t});
                if(t->right != NULL)
                    qu.push({t->right,t});
            }
                
                
            }
            
            
            
            
        }
        
        if(depth >= 0){
            dfs(root,val,cdepth-1);
            
        }
        return root;
        
    }
    void dfs(TreeNode* root,int val,int d){
       
        if(d == 1){
            
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            return;
        }
        
        if(root->left != NULL){
            
            dfs(root->left,val,d-1);
            
            
        }
        
        
        if(root->right != NULL){
           
             dfs(root->right,val,d-1);
            
            
        }
        
        
        
        return;
        
    }
   
};