class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
            int n = quiet.size();
            vector<int> ans(n,-1);

            vector<int>* adj = new vector<int>[n];

            for(int i = 0 ; i < richer.size();i++){
                  adj[richer[i][1]].push_back(richer[i][0]);
            }

               

            for(int i = 0 ; i < n ; i++){
                   stack<int> st;
                   vector<bool> vis(n,false);
                  topological_sort(adj,i,vis,st);
                
                  pair<int,int> mini = {INT_MAX,INT_MAX};
                
                   //st.pop();
                  while(st.size() > 0 ){
                         int fr = st.top();
                         st.pop();
                         if(quiet[fr] < mini.first){
                             mini = {quiet[fr],fr};
                         }
                         
                  }
                
                  if(mini.second == INT_MAX)
                      ans[i] = i;
                
                   ans[i] = mini.second;
                      
                      
                   
                   
            }
        return ans;
        
        
    }
    
    void topological_sort(vector<int> adj[] , int node , vector<bool>& vis ,stack<int>& st){
        
        
         vis[node] = true;
        
        for(auto it : adj[node]){
            
            if(vis[it] == false){
                 topological_sort(adj,it,vis,st);
            }
            
        }
        st.push(node);
        
    }
    
};