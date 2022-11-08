//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
         vector<bool> vis(V,false);
         vector<int> ans;
         ans.push_back(0);
         recur(adj,vis,0,ans);
         return ans;

    }
    
    
    void recur(vector<int> adj[], vector<bool>& vis , int node,vector<int>& ans){
        
        //ans.push_back(node);
        vis[node] = true;
         
         for(int j : adj[node]){
             if(vis[j] == false){
                 ans.push_back(j);
                 recur(adj,vis,j,ans);
                 
             }
         }
        
        
        return;
        
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends