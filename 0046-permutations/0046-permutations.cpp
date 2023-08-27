class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        res = generate(nums,n,res);
        return res;
    }
    vector<vector<int>> generate(vector<int>& nums,int size,vector<vector<int>>& a){
        if(size == 1){
            a.push_back(nums);
            return a;
        }
        for(int i=0;i<size;i++){
            generate(nums,size-1,a);
            if(size%2==1)
                swap(nums[0],nums[size-1]);
            else
                swap(nums[i],nums[size-1]);
        }
        return a;
    }
};