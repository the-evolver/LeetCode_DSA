class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<bool>vis(n,false);
        list<int>* adj = new list<int>[n];
        for(int i = 0 ; i < edges.size();i++){
             int v1 = edges[i][0];
             int v2 = edges[i][1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        vis[source] = true;
        queue<int>qu;
        qu.push(source);
        
        while(qu.size() > 0){
            int f = qu.front();
            qu.pop();
            for(int j : adj[f]){
                if(vis[j] == false){
                    vis[j] = true;
                    qu.push(j);
                }
            }
                  
               
            
        }
                     
        
        return vis[destination];
    }
};