class Solution {
public:
    vector<int>ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        string s ="";
        solve(s,n,k,0);
        //cout<<to_num(s);
        return ans;   
    }
    
    void solve(string s ,int n,int k , int i){
          if(i == n  ){
              ans.push_back(to_num(s));
              return;
          }
              
        
         //
        
        for(int x = 0 ; x <= 9 ; x++){
            if(i == 0 && x != 0){
                solve(s + to_string(x),n,k,i+1);
                
            }else if(i > 0){
                int lst = s[i-1] -'0';
                if(lst - x == k || x - lst == k)
                    solve(s + to_string(x),n,k,i+1);
                
            }
        }
           return;
          
        
        
    }
    int to_num(string s){
        int ans = 0;
        for(int i = 0 ; i < s.length() ;i++){
            ans = ans * 10 + (s[i] - '0');

        }
        return ans;
    }
        
    
    
    
};