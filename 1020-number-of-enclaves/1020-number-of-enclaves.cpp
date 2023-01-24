class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
             if(grid[i][0] == 1 ){
                 dfs(grid,vis,i,0,n,m);
             }
             if(grid[i][m-1] == 1){
                 dfs(grid,vis,i,m-1,n,m);
             }
        }
        
        for(int j = 0 ; j < m ; j++){
             if(grid[0][j] == 1 ){
                 dfs(grid,vis,0,j,n,m);
             }
             if(grid[n-1][j] == 1){
                 dfs(grid,vis,n-1,j,n,m);
             }
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == false)
                    ans++;
            }
        }
        
        return ans;
        
    }
    
    void dfs(vector<vector<int>>& grid , vector<vector<bool>>& vis , int i , int j ,int n , int m ){
        
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == true || grid[i][j] == 0)
            return;
        
         vis[i][j] = true;
        
        dfs(grid,vis,i-1,j,n,m);
        dfs(grid,vis,i+1,j,n,m);
        dfs(grid,vis,i,j-1,n,m);
        dfs(grid,vis,i,j+1,n,m);
        
        
        
        
        
    }
};