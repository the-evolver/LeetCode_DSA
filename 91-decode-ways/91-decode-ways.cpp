class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        vector<int> dp(n,0);
        
        if(s[0] == '0')
            return 0;
        
         dp[0] = 1;
        for(int i = 1 ; i < n ; i++){
            
            if(s[i] == '0' && s[i-1] == '0')
                return 0;
            else if(s[i] == '0' && s[i-1] != '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    dp[i] = ( i > 1 ? dp[i-2] : 0 + 1 );
                    
                }
                
            }else if(s[i] != '0' && s[i-1] == '0'){
                dp[i] = dp[i-1];
                
            }else{
               dp[i] = dp[i-1];
               int n1 = s[i-1] - '0';
               int n2 = s[i] - '0';
               int n = n1* 10 + n2;
               cout<<n1<<" "<<n2<<" "<<n<<endl;
                if(i > 1){
                     
                   
                    if( n <= 26){
                        dp[i] += dp[i-2];
                    }
                }else{
                    if(n <= 26){
                         dp[i] += 1;
                        cout<<" - "<<n<<endl;
                    }
                       // 11
                }
                
            }
            
            
        }
        //cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<endl;
        return dp[n-1];
    }
};