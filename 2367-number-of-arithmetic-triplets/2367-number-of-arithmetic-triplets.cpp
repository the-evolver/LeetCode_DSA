class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        vector<int> hash(400,0);
        for(int i = 0 ; i < nums.size();i++){
            hash[nums[i]]++;
        }
        int sum = 0;
        for(int i = 0 ; i < nums.size();i++){
             if(hash[nums[i] + diff] > 0 && hash[nums[i] + diff + diff] > 0)
                  sum++;
        }
        return sum;
        
    }
};