//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        // agar parent node ke alawa koe bhi adjacent node visited hai 
        // matlb cycle hai tb na
        
        vector<bool>vis(V,false);
        
        for(int i = 0 ; i < V ; i++ ){
            
            if(vis[i] == false && dfs(adj,i,vis,-1) == true){
                return true;
            }
            
            
        }
        
        return false;
        
    }
    
    bool dfs(vector<int> adj[],int node,vector<bool>& vis ,int par){
        
        if(vis[node] == true)
           return true;
           
           vis[node] = true;
           
           for(int it : adj[node]){
                if(it == par ){
                    continue;
                }
                if(vis[it] == true)
                   return true;
                
                if(dfs(adj,it,vis,node) == true)
                 return true;
                
                
           }
        
        return false;
        
        
    }
    
    
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends