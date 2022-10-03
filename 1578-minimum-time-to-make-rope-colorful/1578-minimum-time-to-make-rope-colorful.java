class Solution {
    public int minCost(String colors, int[] neededTime) {
         int n = colors.length();
         int[] dp = new int[n+1];
        for(int i = 0 ; i < dp.length ; i++)
            dp[i] = -1;
         return rem(colors,0,colors.length(),neededTime,dp);
        
        
    }
   
    
    public int rem(String col , int i , int n , int[] neededTime,int[] dp){
        
        if(i >= n - 1){
             dp[n-1] = 0;
             return 0;
        }
         
        if(dp[i] != -1)
            return dp[i];
        
        
        if(col.charAt(i) != col.charAt(i+1))
            return dp[i] = rem(col,i+1,n,neededTime,dp);
        
            
        int maxi = -1;
        int sum = 0;
        int j = i;
        while(j < n && col.charAt(i) == col.charAt(j)){
              sum = sum + neededTime[j];
              //maxi = max(maxi,neededTime[j]);
             if(maxi < neededTime[j])
                 maxi = neededTime[j];
              j++;
        }
        return dp[i] = rem(col,j,n,neededTime,dp) + (sum - maxi);
        
        
    }
}