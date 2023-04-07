class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // sliding window --> max size k if any sliding window contains the distinct valuse then ans is true...
        // for each window we have to calc the value..
        // bruteforce -> using hashmap if the cnt becomes twice and j-i <= k return true;
        
        unordered_map<int,int> up;
        int len = 0;
        int n = nums.size();
        
        for(int j = 0 ; j < n ; j++){
            
            if(len >= k + 1 ){
                up[nums[j-1-len + 1]]--;
                len--;
                
            }
            
            up[nums[j]]++;
            len++;
            
            if(up[nums[j]] >= 2)
                return true;
            
            
        }
        
        return false;
    }
};