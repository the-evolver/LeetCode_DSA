class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                    cnt++;
                   
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        
        return cnt;
        
    }
    
    void dfs(vector<vector<char>>& grid , vector<vector<bool>>& vis, int i,int j, int n , int m){
         vis[i][j] = true;
        if((i-1 >= 0) && (vis[i-1][j] == false) && (grid[i-1][j] == '1')){
            dfs(grid,vis,i-1,j,n,m);
        }
        if((i+1 < n) && (vis[i+1][j] == false) && (grid[i+1][j] == '1')){
            dfs(grid,vis,i+1,j,n,m);
        }
        if((j-1 >= 0) && (vis[i][j-1] == false) && (grid[i][j-1] == '1')){
            dfs(grid,vis,i,j-1,n,m);
        }
        if((j+1 < m) && (vis[i][j+1] == false) && (grid[i][j+1] == '1')){
            dfs(grid,vis,i,j+1,n,m);
        }
        
        
        
    }
};