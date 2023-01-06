class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<bool> vis(n ,false);
        
        int province = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == false){
                province++;
                bfs(isConnected,i,vis);
            }
        }
        
        return province;
        
    }
    
    void bfs(vector<vector<int>>& isConnected,int node,vector<bool>&vis){
        
        queue<int> qu;
        qu.push(node);
        vis[node]=true;
        
        while(qu.size() > 0){
            
            int top = qu.front();
            qu.pop();
            for(int j = 0 ; j < isConnected.size();j++){
                 if(isConnected[top][j] == 1 && vis[j] == false){
                     qu.push(j);
                     vis[j] = true;
                 }
            }
            
        }
        
    }
    
    
};