//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_hp; 
        
        vector<bool>vis(V,false);
        int sum = 0;
        min_hp.push({0,0});
        
        while(min_hp.size() > 0 ){
            
            auto itr = min_hp.top();
            min_hp.pop();
            int node = itr.second;
            int wt   = itr.first;
            if(vis[node] == false){
                vis[node] = true;
                sum += wt;
                for(auto itr : adj[node]){
                     int c_node = itr[0];
                     int c_wt   = itr[1];
                    if(vis[c_node] == false){
                        min_hp.push({c_wt,c_node});
                    }
                }
            }
        }
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends