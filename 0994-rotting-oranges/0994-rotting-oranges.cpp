class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // logic --> bfs ( why ? : because questiona says 4-directionally adjacent)
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> qu;
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2 ){
                    qu.push({i,j});
                    vis[i][j] = true;
                    
                }
            }
        }
        
        while(qu.size() > 0){
            auto it = qu.front();
            qu.pop();
            
            int i = it.first ;
            int j = it.second;
            
            if(i-1 >= 0 && grid[i-1][j] != 0 && vis[i-1][j] == false){
                vis[i-1][j] = true;
                qu.push({i-1,j});
                ans[i-1][j] = ans[i][j] + 1;
            }
            if(j-1 >= 0 && grid[i][j-1] != 0 && vis[i][j-1] == false){
                vis[i][j-1] = true;
                qu.push({i,j-1});
                ans[i][j-1] = ans[i][j] + 1;
            }
            if(i+1 < n && grid[i+1][j] != 0 && vis[i+1][j] == false){
                vis[i+1][j] = true;
                qu.push({i+1,j});
                ans[i+1][j] = ans[i][j] + 1;
            }
            if(j+1 < m && grid[i][j+1] != 0 && vis[i][j+1] == false){
                vis[i][j+1] = true;
                qu.push({i,j+1});
                ans[i][j+1] = ans[i][j] + 1;
            }
            
            
            
        }
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == false)
                    return -1;
                cnt = max(cnt,ans[i][j]);
            }
        }
        return cnt;
        
    }
};