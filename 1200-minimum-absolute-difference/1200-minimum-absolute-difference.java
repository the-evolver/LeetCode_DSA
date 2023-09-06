class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
     
        
        Arrays.sort(arr);
        int min= Integer.MAX_VALUE;
        for(int i=0;i<arr.length-1;i++){
            int a = arr[i]    ;
            int b = arr[i+1]  ;
            int dif = Math.abs(a-b);
            min= Math.min(min,dif);
        }
        List<List<Integer>> ans = new ArrayList();
        
        for(int i=0;i<arr.length-1;i++){
            int a = arr[i]    ;
            int b = arr[i+1]  ;
            int dif = Math.abs(a-b);
            if(dif==min){
                ArrayList<Integer> l = new ArrayList();
                l.add(a);
                l.add(b);
                ans.add(l);
            }
            
            
        }
        
        
        return ans;
        
    }
}