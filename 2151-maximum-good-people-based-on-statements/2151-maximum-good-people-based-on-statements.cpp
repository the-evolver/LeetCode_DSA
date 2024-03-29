class Solution {
private:
    bool possible(vector<vector<int>>& grid, int num) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            if((1 << i) & num) {
                for(int j = 0; j < n; j++) {
                    if(i == j) continue;
                    if(((1 << j) & num) && grid[i][j] == 0) 
                        return false;
                    else if(!((1 << j) & num) && grid[i][j] == 1)
                        return false;
                }
            }
        }
        
        return true;
    }
    
public:
    int maximumGood(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = 1 << n;
        
        int ans = 0;
        for(int i = 1; i < N; i++) {
            if(possible(grid, i))
                ans = max(ans, __builtin_popcount(i));
        }
        
        return ans;
    }
};