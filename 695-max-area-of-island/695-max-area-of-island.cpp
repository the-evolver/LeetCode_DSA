class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int rw = grid.size();
        int cl = grid[0].size();
        vector<vector<bool>>vis(rw,vector<bool>(cl,false));
        
        for(int i = 0 ; i < rw ; i++){
            for(int j = 0 ; j < cl ; j++){
                if(grid[i][j] == 1){
                    int val = dfs(grid,i,j,rw,cl,vis);
                    maxi = max(maxi,val);
                    cout<<" "<<i<<" "<<j<<" --> "<<val<<endl;
                    
                }
            }
        }
        return maxi;
        
    }
    
    int dfs(vector<vector<int>>& grid,int i , int j , int rw , int cl,vector<vector<bool>>&vis){
        if(i < 0 || i == rw || j < 0 || j == cl )
            return 0;
        
        if(grid[i][j] == 0 || vis[i][j] == true)
            return  0;
        
        
        vis[i][j] = true;
        
         int lft = dfs(grid,i,j-1,rw,cl,vis);
         int rgt = dfs(grid,i,j+1,rw,cl,vis);
         int top = dfs(grid,i-1,j,rw,cl,vis);
         int btm = dfs(grid,i+1,j,rw,cl,vis);
        
        
        
       // vis[i][j] = false;
        //cout<<" --> "<<i<<" --> "<<j<<"   "<<lft<<" "<<rgt<<" "<<top<<" "<<btm<<endl;
        return lft + rgt + top + btm + 1;
        
        
    }
};