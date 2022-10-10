class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> y;
        vector<int> x;
        for(int i = n ; i < n + n ; i++){
            y.push_back(nums[i]);
        }
        for(int i = 0 ; i < n ; i++ ){
            x.push_back(nums[i]);
        }
        
        int cnt = 0;
        int i = 0 , j = 0;
        while(cnt < n + n){
            nums[cnt++]   = x[i++];
            nums[cnt++] = y[j++];
            
        }
        return nums;
        
    }
};