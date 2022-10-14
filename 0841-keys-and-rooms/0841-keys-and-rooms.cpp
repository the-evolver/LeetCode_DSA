class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<bool>vis(n,false);
        
        vis[0] = true;
        dfs(vis,rooms,0);
        
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == false){
                 return false;
            }
               
        }
        return true;
        
    }
    
    void dfs(vector<bool>& vis,vector<vector<int>>& rooms,int i){
        
        for(int j = 0 ; j < rooms[i].size();j++){
            if(vis[rooms[i][j]] == false){
                vis[rooms[i][j]] = true;
                dfs(vis,rooms,rooms[i][j]);
            }
        }
        
        
    }
};