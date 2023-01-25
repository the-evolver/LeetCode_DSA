class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
         
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,int>> qu;
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = true;
                    qu.push({i,j});
                }
            }
        }
        
        int max_min = -1;
        
        while(qu.size() > 0 ){
            
            auto it = qu.front();
            qu.pop();
            
            int i = it.first;
            int j = it.second;
            
            if(i - 1 >= 0 && vis[i-1][j] == false){
                
                ans[i-1][j] = ans[i][j] + 1;
                vis[i-1][j] = true;
                qu.push({i-1,j});
                max_min = max(max_min,ans[i-1][j]);
                
            }
            
             
            if(j - 1 >= 0 && vis[i][j-1] == false){
                
                ans[i][j-1] = ans[i][j] + 1;
                vis[i][j-1] = true;
                qu.push({i,j-1});
                max_min = max(max_min,ans[i][j-1]);
                
            }
            
             
            if(i + 1 < n && vis[i+1][j] == false){
                ans[i+1][j] = ans[i][j] + 1;
                vis[i+1][j] = true;
                qu.push({i+1,j});
                max_min = max(max_min,ans[i+1][j]);
            }
            
             
            if(j + 1 < m && vis[i][j+1] == false){
                ans[i][j+1] = ans[i][j] + 1;
                vis[i][j+1] = true;
                qu.push({i,j+1});
                max_min = max(max_min,ans[i][j+1]);
            }
            
            
            
            
            
            
            
        }
        
        
        
        
        
        return max_min;
        
        
        
        
    }
};