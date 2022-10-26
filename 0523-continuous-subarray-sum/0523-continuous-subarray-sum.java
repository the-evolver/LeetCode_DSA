class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        HashSet <Integer> set = new HashSet <>();
        int prevSum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }
            if (set.contains(sum)) {
                return true;
            } 
            set.add(prevSum);
            prevSum = sum;
        }
        return false;
    }
}