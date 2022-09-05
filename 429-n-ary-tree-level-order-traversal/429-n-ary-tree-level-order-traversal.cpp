/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
            return {};
        
        queue<Node*> qu;
        qu.push(root);
        qu.push(NULL);
        vector<vector<int>>ans;
        vector<int> temp;
       
        while(qu.empty() == false){
               Node* curr = qu.front();
               qu.pop();
               if(curr == NULL){
                   if(qu.size() > 0)
                       qu.push(NULL);
                   
                    ans.push_back(temp);
                    temp.clear();
                   
               }else{
                    temp.push_back(curr->val);
                   for(int i = 0 ; i < curr->children.size();i++){
                      qu.push(curr->children[i]);
                   }
               }
              
        }
        return ans;
        
    }
};