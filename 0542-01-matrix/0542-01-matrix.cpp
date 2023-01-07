class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<int,int>> qu;
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        vector<vector<int>>  ans(row,vector<int>(col,0));
       
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(mat[i][j] == 0){
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
            
            if(i-1 >= 0 && vis[i-1][j] == false){
                vis[i-1][j] = true;
                ans[i-1][j] = ans[i][j] + 1;
                qu.push({i-1,j});
            }
            if(i+1 < row && vis[i+1][j] == false){
                vis[i+1][j] = true;
                ans[i+1][j] = ans[i][j] + 1;
                qu.push({i+1,j});
            }
            if(j-1 >= 0 && vis[i][j-1] == false){
                vis[i][j-1] = true;
                ans[i][j-1] = ans[i][j] + 1;
                qu.push({i,j-1});
            }
            if(j+1 < col && vis[i][j+1] == false){
                vis[i][j+1] = true;
                ans[i][j+1] = ans[i][j] + 1;
                qu.push({i,j+1});
            }
            
            
            
        }
        
        return ans;
        
        
    }
};