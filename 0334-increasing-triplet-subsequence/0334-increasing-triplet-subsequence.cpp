class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size() ;
        long long int a = (long) INT_MAX + 1 , b = (long)INT_MAX + 1 ;
        
        for(int i = 0 ; i < n ; i++){
            
             if(nums[i] <= a)
                 a = nums[i];
              else if(nums[i] <= b)
                b = nums[i];
              else 
                  return true;
        }
        return false;
        
    }
};