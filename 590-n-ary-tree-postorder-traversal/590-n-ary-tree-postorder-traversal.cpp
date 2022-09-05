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
    vector<int> postorder(Node* root) {
        if(root == NULL)
            return {};
        
         vector<int> pre_order;   // just for fun 
         vector<int> post_order;
        
         stack<pair<Node*,int>> st ; // node , state 
        
         st.push({root,-1});
        
         while(st.size() > 0){
             pair<Node*,int> curr = st.top();
             if(curr.second == -1){
                pre_order.push_back(curr.first->val);
                st.top().second++;
             }else{
                 if(curr.second == curr.first->children.size()){
                     post_order.push_back(curr.first->val);
                     st.pop();
                 }
                 else{
                  st.push({curr.first->children[st.top().second++],-1});
                 }
                 
             }
             
         }
        return post_order;
        
    }
};