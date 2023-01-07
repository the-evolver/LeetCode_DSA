class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
         vector<vector<bool>>vis(row,vector<bool>(col,false));
         vector<vector<int>>ans(row,vector<int>(col,0));
        
        queue<pair<int,int>> qu;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                    vis[i][j] = true;
                
                }
                
            }
        }
        
        while(qu.size() > 0 ){
            
            pair<int,int> pr = qu.front();
            qu.pop();
            
            int i = pr.first;
            int j = pr.second;
            
            if(i-1 >= 0 && vis[i-1][j] == false && grid[i-1][j] == 1){
                qu.push({i-1,j});
                ans[i-1][j] = ans[i][j] + 1;
                vis[i-1][j] = true;
                grid[i-1][j] = 2;
                
            }
            if(j-1 >= 0 && vis[i][j-1] == false && grid[i][j-1] == 1){
                qu.push({i,j-1});
                ans[i][j-1] = ans[i][j] + 1;
                vis[i][j-1] = true;
                grid[i][j-1] = 2;
                
            }
            if(i+1 < row && vis[i+1][j] == false && grid[i+1][j] == 1){
                qu.push({i+1,j});
                ans[i+1][j] = ans[i][j] + 1;
                vis[i+1][j] = true;
                grid[i+1][j] = 2;
                
            }
            if(j+1 < col && vis[i][j+1] == false && grid[i][j+1] == 1){
                qu.push({i,j+1});
                ans[i][j+1] = ans[i][j] + 1;
                vis[i][j+1] = true;
                grid[i][j+1] = 2;
                
            }
            
            
            
        }
        int cnt = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                 cnt = max(cnt,ans[i][j]);
                 if(grid[i][j] == 1){
                     //cout<<i<<"  "<<j<<endl;
                     return -1;
                 }
                     
            
            }
        }
       return cnt;
        
        
        
    }
};