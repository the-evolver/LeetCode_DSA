class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        int mx = 1;
         
        for(int i = 1 ; i < n ; i++){
            int curr = 0;
            int j = i-1;
             for(; j >= 0 ; j--){
                  if(nums[j] < nums[i]){
                      curr = max(curr,dp[j]+1);
                  }else{
                      curr = max(curr,1);
                  }
                 
             }
            
            dp[i] = curr;
            mx = max(mx,dp[i]);
            
            
        }
        
        return mx;
        
    }
};