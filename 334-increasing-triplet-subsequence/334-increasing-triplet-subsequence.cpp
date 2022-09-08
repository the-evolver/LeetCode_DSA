class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        // greedy approach ::
        long long a = (long long)INT_MAX + 1 , b = (long long)INT_MAX + 1 , c = (long long)INT_MAX + 1;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            
            if(nums[i] <= a)
                a = nums[i];
            else if(nums[i] <= b)
                  b = nums[i];
            else if(nums[i] <= c)
                c = nums[i];
            
           if( a !=  (long long)INT_MAX + 1 && b != (long long)INT_MAX + 1 && c != (long long)INT_MAX + 1)
                 return true;                
    
        }
        return false;
        
    }
};