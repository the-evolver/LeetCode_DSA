class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rw = grid.size();
        int cl = grid[0].size();
        int ans = 0;
        vector<vector<bool>>vis(rw,vector<bool>(cl,false));
        
        for(int i = 0 ; i < rw ; i++){
            for(int j = 0 ; j < cl ; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    ans++;
                    dfs(grid,rw,cl,i,j,vis);
                }
                    
            }
        }
        
        return ans;
        
    }
    
    void dfs(vector<vector<char>>& grid,int rw,int cl , int i , int j ,vector<vector<bool>>&vis ){
         if(i < 0 || i == rw || j < 0 || j == cl)
             return ;
        if(grid[i][j] == '0' || vis[i][j] == true)
             return;
        
        vis[i][j] = true;
        dfs(grid,rw,cl,i-1,j,vis);
        dfs(grid,rw,cl,i+1,j,vis);
        dfs(grid,rw,cl,i,j-1,vis);
        dfs(grid,rw,cl,i,j+1,vis);
    }
};