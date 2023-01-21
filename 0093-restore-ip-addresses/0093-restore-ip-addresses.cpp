class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        
        valid(s,0,0,"");
        return ans;
        // cout<<str_to_num("2333423")<<endl;
        
        
         return ans;
    }
    
    void valid(string s , int dots , int i ,string news){
        
        if(dots == 3){
              //cout<<news<<endl;
            string curr = s.substr(i,s.length()-i);
            long long num = str_to_num(curr);
            if(num > 255 || (curr[0] == '0' && curr.length() > 1))
                return;
            
          
            ans.push_back(news+s.substr(i,s.length()-i));
        }
        
    // 25.55.52.
    // 255.52.25.
    // 255.52.255.

        
        for(int j = i+1 ; j < s.length() ; j++){
             
            string curr = s.substr(i,j-i);
            long long num = str_to_num(curr);
            if(num > 255 || (curr[0] == '0' && curr.length() > 1))
                break;
            
            valid(s,dots+1,j,news + curr+'.');
        }
        return;
        
    }
    
    long long str_to_num(string curr){
        
        long long  ans = 0;
        for(int i = 0 ; i < curr.length() ; i++){
            
            ans = ans * 10 + (curr[i]-'0');

        }
        return ans;
        
    }
    
    
};