class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        long long  ans = 0;
        
        int n = nums.size();
        
        long long src = 0;
        
        long long curr_set = 0;
        
        for( long long i = 0 ; i < n ; i++ ){
                
            while((curr_set & nums[i] )!= 0){
                curr_set = curr_set ^ nums[src];
                src++;
            }
            
            curr_set = curr_set ^ nums[i];
             ans = max(ans,i - src + 1);
        
        
        }
        
        return ans;
        
        
        
    }
};