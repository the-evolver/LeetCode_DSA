class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        vector<int> row_ones;
        vector<int> col_ones;
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++){
             int sum = 0;
            for(int j = 0 ; j < m ; j++){
                 sum += grid[i][j];
            }
            row_ones.push_back(sum);
        }
         for(int j = 0 ; j < m ; j++){
             int sum = 0;
            for(int i = 0 ; i < n ; i++){
                 sum += grid[i][j];
            }
            col_ones.push_back(sum);
        }
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                ans[i][j] = 2*(row_ones[i] + col_ones[j]) -(n+m);
            }
        }
        return ans;
    }
};