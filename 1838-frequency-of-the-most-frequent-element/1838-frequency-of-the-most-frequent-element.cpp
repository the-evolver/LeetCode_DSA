class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        long long  cumm_sum = 0;
        
        long long  src = 0 , ans = 0;
        long long  n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            
            long long req = ((i - src) * nums[i]) - cumm_sum;
            
            while(req > k ){
                
                req = req - (nums[i] - nums[src]);
                cumm_sum -= nums[src];
                src++;
                if(src == i)
                    break;
            }
            
            cumm_sum += nums[i];
            ans = max(ans,i-src+1);
            
            
            
        }
        
        return ans;
        
        
    }
};