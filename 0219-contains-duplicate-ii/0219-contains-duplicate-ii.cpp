class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int>up;
        int len = nums.size();
        for(int i = 0 ; i < len ; i++){
             if(up.find(nums[i]) == up.end())
                 up[nums[i]] = i;
             else{
                 if(i - up[nums[i]] <= k)
                     return true;
                 up[nums[i]] = i;
                 
             }
            
        }
        return false;
    }
};