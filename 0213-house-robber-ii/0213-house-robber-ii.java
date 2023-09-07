class Solution {
	public static int rob(int[] nums, int s, int e) {
		int n1 = 0;
		int n2 = 0;
		if (e > s)
			n1 = nums[e - 1];
		if (e > s + 1)
			n2 = Math.max(nums[e - 2], n1);

		for (int i = e - 3; i >= s; i--) { 
			int ans = Math.max(n2, nums[i] + n1); 
			n1 = n2;
			n2 = ans;
		}
		return n2;
	}

	public static int rob(int[] nums) {
		int n = nums.length;
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];
		if (n == 2)
			return Math.max(nums[1], nums[0]);
		return Math.max(rob(nums, 0, n - 1), rob(nums, 1, n));
	}
}