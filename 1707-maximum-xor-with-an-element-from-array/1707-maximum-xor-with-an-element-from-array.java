class Solution {
    public class Trie {
	private class Node {
		int data;
		Node[] children;
         public Node(int data) {
			this.data = data;
			this.children = new Node[2];
		}
	}
	private Node root;
	int count;
	public Trie() {
		this.root = new Node(-1);
		this.count = 0;
	}

	public void addWord(int num) {
        this.count++;
		Node curr = root;
		for (int i = 30; i >= 0; i--) {
			int mask = 1 << i;
			int bit = num & mask;
			bit = (bit != 0) ? 1 : 0;
			Node temp = curr.children[bit];
			if (temp == null) {
				temp = new Node(bit);
				curr.children[bit] = temp;
			}
			curr = temp;
		}
	}
	public int searchWord(int num) {
		if (count == 0)
			return -1;
		Node curr = root;
		int ans = 0;
		for (int i = 30; i >= 0; i--) {
			int mask = 1 << i;
			int bit = num & mask;
			bit = (bit != 0) ? 1 : 0;
			int toggle = bit ^ 1;
			Node temp = curr.children[toggle];
			if (temp != null) {
				curr = temp;
				ans |= mask;
			} else
				curr = curr.children[bit];
		}
		return ans;
	}
}
public int[] maximizeXor(int[] nums, int[][] queries) {

	Trie trie = new Trie();
	int len = queries.length;
	int len2 = nums.length;
	int[] ans = new int[len];

	int[][] temp = new int[len][3];
	for (int i = 0; i < len; i++) {
		temp[i][0] = queries[i][0];
		temp[i][1] = queries[i][1];
		temp[i][2] = i;
	}

	Arrays.sort(nums);
	Arrays.sort(temp, new Comparator<int[]>() {
		@Override
		public int compare(int[] o1, int[] o2) {
			return o1[1] - o2[1];
		}
	});

	int index = 0;
	for (int[] query : temp) {
		while (index < len2 && nums[index] <= query[1]) {
			trie.addWord(nums[index]);
			index++;
		}

		ans[query[2]] = trie.searchWord(query[0]);
	}
	return ans;
}
}