class Solution {
	int n;
	int[] data;
	public int minOperations(int[] target, int[] arr) {
		int m = target.length, an = arr.length;
		Map<Integer, List<Integer>> map = new HashMap<>();
		for(int i = 0; i < an; i++){
			int cur = arr[i];
			List<Integer> cl = map.getOrDefault(cur, new ArrayList<>());
			cl.add(i);
			map.put(cur, cl);
		}
		init(an);
		int mm = 0;
		for(int i = 0; i < m; i++){
			int cur = target[i];
			List<Integer> cl = map.getOrDefault(cur, new ArrayList<>());
			int clen = cl.size();
			for(int j = clen - 1; j >=0; j--){
				int pos = cl.get(j);
				int prev = query(0, pos, 0,0,n);
				int curv = prev + 1;
				update(pos, curv);
				if(mm < curv) mm = curv;
			}
		}
		return m - mm;
	}
	void init(int n_){
		n = 1;
		while(n < n_) n *= 2;
		data = new int[2 * n - 1];
		for(int i = 0; i < 2 * n - 1; i++)data[i] =0;
	}

	void update(int k, int a){
		k += n - 1;
		data[k] = a;
		while(k > 0){
			k = (k - 1)/2;
			data[k] = Math.max(data[k * 2 + 1], data[k * 2 + 2]);
		}
	}

	int query(int a, int b, int k, int l, int r){
		if(r <= a || b <= l)return 0;
		if(a <= l && r <= b){
			return data[k];
		} else {
			int vl = query(a,b,k * 2 + 1, l, (l + r)/2);
			int vr = query(a,b,k * 2 + 2, (l + r)/2, r);
			return Math.max(vl, vr);
		}

	}
}