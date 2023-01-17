class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size(); // size of nums
        int i = 0; // sliding window starting point
        int ans = 0;  // ans variable stores ans
        int cnt_0 = 0; // keeps track of no of zeros in current window
        int cumm_sum = 0; // ** cumm_sum of sliding window
        
        for(int j = 0 ; j < n ; j++){
            
            if(nums[j] == 1)
              cumm_sum++; // adding in window
            else{
                cnt_0++;
            }
            while(cnt_0 > 1){
                  cumm_sum = cumm_sum - nums[i]; // removing from window
                  if(nums[i] == 0){
                      cnt_0--;
                  }
                 i++;
            }
            ans = max(ans,cumm_sum);
        }
        if( ans == n)
            ans--;
        
        return ans;
    }
};