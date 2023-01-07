class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        int row  = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        queue<pair<int,int>> qu;
        for(int i = 0 ; i  < row ; i++){
            for(int j = 0 ; j < col ; j++){
                 
                if( grid[i][j] == 1 && ( i == 0 || i + 1 == row || j == 0 || j+1 == col ) ){
                    qu.push({i,j});
                    vis[i][j] = true;
                    
                    
                }
            
            }
        }
        
        while(qu.size() > 0){
            
            pair<int,int> co = qu.front();
            qu.pop();
            int i = co.first;
            int j = co.second;
            
            if(i-1 >= 0 && vis[i-1][j] == false && grid[i-1][j] == 1){
                vis[i-1][j] = true;
                qu.push({i-1,j});
            }
            if(j-1 >= 0 && vis[i][j-1] == false && grid[i][j-1] == 1){
                vis[i][j-1] = true;
                qu.push({i,j-1});
            }
            if(i+1 < row && vis[i+1][j] == false && grid[i+1][j] == 1){
                vis[i+1][j] = true;
                qu.push({i+1,j});
            }
            if(j+1 < col && vis[i][j+1] == false && grid[i][j+1] == 1){
                vis[i][j+1] = true;
                qu.push({i,j+1});
            }
            
            
            
        }
        
        int cnt = 0;
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                
                if(grid[i][j] == 1 && vis[i][j] == false){
                    cnt++;
                }
                
            }
        }
        
        return cnt;
        
    }
};