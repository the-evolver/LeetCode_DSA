class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int max_ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
             
            
            int ans = 0;
            for(int j = i + 1 ; j < n ; j++){
                 if(nums[i] < nums[j])
                     ans = max(ans,dp[j]);
            }
            dp[i] = ans + 1;
            max_ans = max(max_ans,dp[i]);
            
            
        }
        return max_ans;
        
    }
};