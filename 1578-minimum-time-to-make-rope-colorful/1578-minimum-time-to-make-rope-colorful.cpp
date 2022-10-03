class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
         int n = colors.length();
         vector<int> dp(n+1,0);
         
        
         for(int i = n - 2 ; i >= 0 ; i--){
             
             if(colors[i] == colors[i+1] ){
                 if( i > 0 && colors[i] == colors[i-1]){
                    //
                     
                 }else{
                      int maxi = INT_MIN;
                      int sum = 0;
                     int j = i;
                      while(j < n && colors[i] == colors[j]){
                              sum = sum + neededTime[j];
                              maxi = max(maxi,neededTime[j]);
                              j++;
                          }
                      dp[i] = dp[j] + (sum - maxi);
                     

                 }
                 
                 
                 
             }else{
                 dp[i] = dp[i+1] ;
                 
             }
             
         }
        return dp[0];
        
         
        
        
    }
    
//     int rem(string col , int i , int n , vector<int>& neededTime,vector<int>& dp){
//         if(i >= n - 1){
//              dp[n-1] = 0;
//              return 0;
//         }
         
//         if(dp[i] != -1)
//             return dp[i];
        
        
//         if(col[i] != col[i+1])
//             return dp[i] = rem(col,i+1,n,neededTime,dp);
        
            
//         int maxi = INT_MIN;
//         int sum = 0;
//         int j = i;
//         while(j < n && col[i] == col[j]){
//               sum = sum + neededTime[j];
//               maxi = max(maxi,neededTime[j]);
//               j++;
//         }
//         return dp[i] = rem(col,j,n,neededTime,dp) + (sum - maxi);
        
        
//     }
};