


class Solution {
public:
    long long countLess(vector<int>& nums, int val) {
    long long res = 0;
    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
        while(i < j && nums[i] + nums[j] > val)
            --j;
        res += j - i;
    }        
    return res;
}
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(begin(nums), end(nums));
    return countLess(nums, upper) - countLess(nums, lower - 1);
}
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
//         sort(nums.begin(),nums.end());
        
//         long long  less_than_lower = solve(nums,lower-1);
//         long long less_than_upper = solve(nums,upper);
        
//         return less_than_upper - less_than_lower;
        
//     }
    
//     long long  solve(vector<int>& nums,int val){
        
//         long long ans = 0;
//         int n = nums.size();
//         int en = n - 1;
//         for(int i = 0 ; i < n ; i++){
            
            
//             while(en > i && nums[i] + nums[en] > val)
//                 en--;
            
//             ans += (en - i);
            
            
//         }
//         return ans;
//     }
    
};