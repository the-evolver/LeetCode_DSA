class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int ans = 0;
        int cnt_0 = 0;
        int cumm_sum = 0;
        for(int j = 0 ; j < n ; j++){
            
            if(nums[j] == 1)
              cumm_sum++;
            else{
                cnt_0++;
            }
            
            while(cnt_0 > 1){
                  cumm_sum = cumm_sum - nums[i];
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