class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> qu;
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        vector<vector<int>>  ans(n,vector<int>(m,0));
        
        
        for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 1){
                    vis[i][j] = true;
                    qu.push({i,j});
                }
                
            }
        }
        int maxi = 0;
        while(qu.size() > 0 ){
            
               auto it = qu.front();
               qu.pop();
            
              int i = it.first;
              int j = it.second;
               
              if(i - 1 >= 0 && vis[i-1][j] == false ){
                  ans[i-1][j] = ans[i][j] + 1;
                  vis[i-1][j] = true;
                  maxi = max(maxi,ans[i-1][j]);
                  qu.push({i-1,j});
              }
             if(i + 1 < n  && vis[i+1][j] == false ){
                  ans[i+1][j] = ans[i][j] + 1;
                  vis[i+1][j] = true;
                  qu.push({i+1,j});
                 maxi = max(maxi,ans[i+1][j]);
              }
             if(j - 1 >= 0 && vis[i][j-1] == false ){
                  ans[i][j-1] = ans[i][j] + 1;
                  vis[i][j-1] = true;
                  qu.push({i,j-1});
                 maxi = max(maxi,ans[i][j-1]);
              }
             if(j + 1 < m  && vis[i][j+1] == false ){
                  ans[i][j+1] = ans[i][j] + 1;
                  vis[i][j+1] = true;
                  qu.push({i,j+1});
                 maxi = max(maxi,ans[i][j+1]);
              }
           
        }
        
        
        return maxi == 0 ? -1 : maxi;
        
    }
};