class Solution {
    int[] posMap;
    public int oddEvenJumps(int[] arr) {
        int size = arr.length;
        boolean[] odd = new boolean[size];
        boolean[] even = new boolean[size];
        posMap = new int[100001];
        Arrays.fill(posMap, -1);
        posMap[arr[size-1]] = size-1;
        odd[size -1] = even[size -1] = true;
        int count = 1;
        for (int i = size-2; i >= 0; i--) {
            int curr = arr[i];
            int maxi = getMax(curr);
            int mini = getMin(curr);
            if (mini != -1) {
                if(even[mini]) {
                   
                    odd[i] = even[mini];
                    count++;
                }
            }
            if(maxi != -1){
                even[i] = odd[maxi];
            }
            posMap[arr[i]] = i;
        }
        return count;
    }
    
    private int getMax(int cnt) {
        for(int i = cnt; i >=0 ; i--){
            if(posMap[i] != -1) {
                return posMap[i];
            }
        }
        return -1;
    }
    
    private int getMin(int cnt) {
        for(int i = cnt; i < 100001; i++){
            if(posMap[i] != -1) {
                return posMap[i];
            }
        }
        return -1;
    }
}