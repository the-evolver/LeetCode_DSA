class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        dfs(grid,row,col,n,m,color,vis);
        return grid;
        
        
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j,int row,int col, int color,vector<vector<bool>>& vis){
        //cout<<i<<" .... "<<j<<endl;
        if(i < 0 || i == row || j < 0 || j == col || vis[i][j] == true)
            return;
        
        //cout<<i<<" ;;; "<<j<<endl;
        
        vis[i][j] = true;
        bool change = false;
        if(i == 0 || i == row - 1 || j == 0 || j == col - 1){
           //cout<<i<<" : "<<j<<endl;
           //grid[i][j] = color;
            change = true;
        }
        else if((i - 1 >= 0 && grid[i-1][j] != grid[i][j]) || (i+1 < row  && grid[i+1][j] != grid[i][j])   || (j - 1 >= 0 && grid[i][j-1] != grid[i][j])  || (j+1 < col  && grid[i][j+1] != grid[i][j])   ){
             //cout<<i<<" , "<<j<<endl;
            //cout<<grid[i+1][j]<<" ,,, "<<grid[i][j]<<" ,,, "<<grid[i][j+1]<<endl;
             //grid[i][j] = color;
            change = true;
        }
            
        
        
        
        
         if(i-1 >= 0 && grid[i-1][j] == grid[i][j])
             dfs(grid,i-1,j,row,col,color,vis);
        
        if(i+1 < row && grid[i+1][j] == grid[i][j])
             dfs(grid,i+1,j,row,col,color,vis);
        
        if(j-1 >= 0 && grid[i][j-1] == grid[i][j])
             dfs(grid,i,j-1,row,col,color,vis);
        
        if(j+1 < col  && grid[i][j+1] == grid[i][j])
             dfs(grid,i,j+1,row,col,color,vis);
        
        
        if(change == true)
            grid[i][j] = color;
        
        
    }
};