class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        vector<pair<int,int>> island1;
        
        vector<pair<int,int>> island2;
        
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            
                for(int j = 0 ; j < m ; j++){
                    
                         if(vis[i][j] == false && grid[i][j] == 1){
                             
                                 if(cnt == 0){
                                     dfs(grid,i,j,n,m,vis,island1);
                                     cnt++;
                                 }else{

                                     dfs(grid,i,j,n,m,vis,island2);

                                 }
                        }
                    
                }
        }
        
        int minm = INT_MAX;
        for(int i = 0 ; i < island1.size() ; i++){
            for(int j = 0 ; j < island2.size();j++){
                minm = min(minm,abs(island1[i].first-island2[j].first) + abs(island1[i].second-island2[j].second));
            }
        }
        
        return minm-1;
        
        
       
    }
    
    void dfs(vector<vector<int>>& grid, int i , int j , int n , int m , vector<vector<bool>>& vis , vector<pair<int,int>>& ans){
        
        if( i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0 || vis[i][j] == true)
            return;
        
        vis[i][j] = true;
        
        ans.push_back({i,j});
        
        dfs(grid,i-1,j,n,m,vis,ans);
        dfs(grid,i+1,j,n,m,vis,ans);
        dfs(grid,i,j-1,n,m,vis,ans);
        dfs(grid,i,j+1,n,m,vis,ans);
        
        
    }
    
    
};