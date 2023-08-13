class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> vt;
        for(int i = 0 ; i < nums.size() ; i++){
            vt.push_back({nums[i],i});
        }
        sort(vt.begin(),vt.end());
        int i = 0 , j = nums.size()-1;
        while( i < j ){
            int sum = vt[i].first + vt[j].first;
            if(sum == target)
                return {vt[i].second,vt[j].second};
            if(sum > target)
                j--;
            if(sum < target)
                i++;
        }
        
        return {-1,-1};
    }
};