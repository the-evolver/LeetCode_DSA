class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int ans = INT_MAX;
        int curr_sum = 0;
        int n = nums.size();
        
        
        
        for(int i = 0 , j = 0 ; j <= n ;){
                
                if(curr_sum < target){
                     if(j < n)
                     curr_sum += nums[j];
                    
                     j++;
                   
                 }else{
                   if(ans > j - i)
                       ans = j - i;
                   curr_sum -= nums[i];
                   i++;
                 
                }
            
        }
        
        return (ans == INT_MAX) ? 0 : ans ;
        
    }
};