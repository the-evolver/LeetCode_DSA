
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        
        queue<pair<pair<int,int>,int>> qu;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                    if(mat[i][j] == 0){
                        vis[i][j] = true;
                        qu.push({{i,j},0});
                    }
                
            }
        }
        
        while(qu.size()){
            
            auto it = qu.front();
            qu.pop();
            
            int i = it.first.first;
            int j = it.first.second;
            
            int sum = it.second;
            
            if(mat[i][j] == 1){
                ans[i][j] = sum;
                
            }
            
            
            if(i-1 >= 0 && vis[i-1][j] == false){
                vis[i-1][j] = true;
                qu.push( { {i-1 , j }, sum + 1 } );
            }
            if(j-1 >= 0 && vis[i][j-1] == false){
                vis[i][j-1] = true;
                qu.push( { {i , j-1 }, sum + 1 } );
            }
            if(i+1 < n && vis[i+1][j] == false){
                vis[i+1][j] = true;
                qu.push( { {i+1 , j }, sum + 1 } );
            }
            if(j+1 < m && vis[i][j+1] == false){
                vis[i][j+1] = true;
                qu.push( { {i , j+1 }, sum + 1 } );
            }
            
            
            
            
        }
        
        return ans;
        
    }
};