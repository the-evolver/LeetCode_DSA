class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
             if(abs(nums[i]) < abs(mini) || (abs(nums[i]) == abs(mini) && nums[i] > mini))
                 mini = nums[i];
        }
        
        return mini;
        
        
    }
};