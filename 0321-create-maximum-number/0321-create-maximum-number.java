class Solution {
	public int[] findLexMax(int[] nums, int k) {
		int n = nums.length;
		Stack<Integer> st = new Stack<>();
		int[] res = new int[k];
		int rem = n - k;
		for (int i = 0; i < n; i++) {
			while (!st.isEmpty() && st.peek() < nums[i] && rem > 0) {
				st.pop();
				rem--;
			}
			st.push(nums[i]);

		}
        while (rem > 0) {
			st.pop();
			rem--;
		}
		for (int i = k - 1; i >= 0; i--) {
			res[i] = st.pop();
		}
		return res;
	}
	private static boolean findMax(int[] arr1, int[] arr2, int p1,int p2) {
		while (p1 < arr1.length && p2 < arr2.length) {
			if (arr1[p1] < arr2[p2]) {
				return false;
			} else if (arr1[p1] > arr2[p2]) {
				return true;
			} else {
				p1++;
				p2++;
			}
		}
        return p1!=arr1.length; 
	}
       private int[] merge(int[] nums1, int[] nums2, int k) {
		int[] res = new int[k];
		int resIndex = 0;
		int p1 = 0;
		int p2 = 0;
        
		while (resIndex<res.length) {
			res[resIndex++]=findMax(nums1,nums2,p1,p2)?nums1[p1++]:nums2[p2++];
		}
		return res;
	}

	public int[] maxNumber(int[] nums1, int[] nums2, int k) {
		int len1 = nums1.length;
		int len2 = nums2.length;
		int[] maxRes = new int[k];
		for (int i = 0; i <= k; i++) { 
			int j = k - i;
			if (i <= len1 && (k - i) <= len2) { 
				int[] maxLex1 = findLexMax(nums1, i);
				int[] maxLex2 = findLexMax(nums2, j);
				int[] res = merge(maxLex1, maxLex2, k);
				boolean compareRes = findMax(res, maxRes,0,0);
				if (compareRes) {
					maxRes = res;
				}
			}
		}
		return maxRes;
	}
}