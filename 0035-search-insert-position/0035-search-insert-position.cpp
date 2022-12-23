class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0 , en = n-1, mid;
        while(st <= en){
            mid = (st + en)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                st = mid + 1;
            else if(nums[mid] > target)
                en = mid - 1;
            
        }
        return st;
    }
};