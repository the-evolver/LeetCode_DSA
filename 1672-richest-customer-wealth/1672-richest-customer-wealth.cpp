class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_sum = 0;
        int n = accounts.size();
        int m = accounts[0].size();
        
        for(int i = 0 ; i < n ; i++){
            int curr = 0;
            for(int j = 0 ; j < m ; j++){
                curr += accounts[i][j];
            }
            if(max_sum < curr)
                 max_sum = curr;
        }
        
        return max_sum ;
        
    }
};