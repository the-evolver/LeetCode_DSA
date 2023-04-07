class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // sliding window --> max size k if any sliding window contains the distinct valuse then ans is true...
        // for each window we have to calc the value..
        // bruteforce -> using hashmap if the cnt becomes twice and j-i <= k return true;
        
        unordered_map<int,int> up;
        int len = 0;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            
            if(up.find(nums[i]) == up.end()){
                up[nums[i]] = i;
            }else{
                if( i - up[nums[i]] <= k)
                    return true;
                else
                    up[nums[i]] = i;
            }
            
        }
        
        return false;
    }
};