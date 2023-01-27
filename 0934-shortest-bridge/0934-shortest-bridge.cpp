class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> qu;
        int cnt = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j,n,m,qu,vis);
                    cnt++;
                }
                if(cnt > 0)
                    break;
            }
            if(cnt > 0)
                    break;
        
        }
            
       int ans = 0;
    
       qu.push({-1,-1});
            
       while(qu.size() > 0){
           
           auto it = qu.front();
           qu.pop();
           
           int i = it.first;
           int j = it.second;
           //cout<<i<<" "<<j<<endl;
           if(i == -1){
               ans++;
               qu.push({-1,-1});
           }
           else{
               
               if(i - 1 >= 0 && vis[i-1][j] == false){
                   
                   if(grid[i-1][j] == 1){
                        return ans;
                   }
                      
                   vis[i-1][j] = true;
                   qu.push({i-1,j});
                   
               }
                if(j - 1 >= 0 && vis[i][j-1] == false){
                   if(grid[i][j-1] == 1){
                        return ans;
                   }
                      
                   vis[i][j-1] = true;
                   qu.push({i,j-1});
                   
               }
               if(i + 1 < n && vis[i+1][j] == false){
                   if(grid[i+1][j] == 1){
                        return ans;
                   }
                      
                   vis[i+1][j] = true;
                   qu.push({i+1,j});
               }
               if(j+1 < m && vis[i][j+1] == false){
                   if(grid[i][j+1] == 1){
                        return ans;
                   }
                      
                   vis[i][j+1] = true;
                   qu.push({i,j+1});
               }
               
               
               
           }
               
       }
            
            
            
        return 0;
    }
     void dfs(vector<vector<int>>& grid , int i , int j , int n , int m , queue<pair<int,int>>& qu , vector<vector<bool>>& vis){
         
         if(i < 0 || j < 0 || i == n || j == m || vis[i][j] == true || grid[i][j] == 0){
             return ;
         }
         
         vis[i][j] = true;
         qu.push({i,j});
         
         dfs(grid,i-1,j,n,m,qu,vis);
         dfs(grid,i+1,j,n,m,qu,vis);
         dfs(grid,i,j-1,n,m,qu,vis);
         dfs(grid,i,j+1,n,m,qu,vis);
         
         
         
         
         
         
     }
};