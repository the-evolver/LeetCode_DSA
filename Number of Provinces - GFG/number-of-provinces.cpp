//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        
        int cnt = 0;
       
        vector<bool> vis(V,false);
        
        for(int i = 0 ; i < V ; i++){
            if(vis[i] == false){
                cnt++;
                dfs(adj,V,i,vis);
            }
        
    }
     return cnt;
    }
    
    void dfs(vector<vector<int>> adj , int v , int i,vector<bool>& vis){
         
         for(int j = 0 ; j < adj[i].size();j++){
             if(adj[i][j] == 1 && vis[j] == false){
                 vis[j] = true;
                 dfs(adj,v,j,vis);
             }
         }
        
    }
   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends