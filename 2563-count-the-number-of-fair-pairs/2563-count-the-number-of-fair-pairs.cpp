class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        
        sort(nums.begin(),nums.end());
        
        long long  less_than_lower = solve(nums,lower-1);
        long long less_than_upper = solve(nums,upper);
        
        return less_than_upper - less_than_lower;
        
     }
    
    long long  solve(vector<int>& nums,int val){
        
        long long ans = 0;
         int n = nums.size();
         int en = n - 1;
         for(int i = 0 ; i < n ; i++){
            
            
             while(en > i && nums[i] + nums[en] > val)
                 en--;
             
             if(en - i > 0 )
             ans += (en - i);
            
            
         }
         return ans;
     }
    
};