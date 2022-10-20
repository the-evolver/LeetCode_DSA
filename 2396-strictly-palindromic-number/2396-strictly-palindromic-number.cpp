class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        for(int i = 2 ; i < n - 1 ; i++){
             string curr = base(n,i);
             
             if(pali(curr) == false)
                 return false;
        }
        //cout<<pali("001");
        return true;
    }
    
    string base(int n , int b){
        
        string ans ="";
        while( n > 0){
            
            if(n >= b){
                int curr = n % b;
                n = n/b;
                ans += to_string(curr);
            }else{
                ans += to_string(n);
                n = 0;
            }
            
        }
        return ans;
        
        
    }
    bool pali(string curr){
        
        for(int i = 0 , j = curr.length() - 1; i < j  ; i++,j--){
             
            if(curr[i] != curr[j]){
                return false;
                
            }
                
        }
        
        return true;
    }
};