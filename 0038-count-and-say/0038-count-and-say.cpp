class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1){
            return "1";
        }
        
        string say = countAndSay(n-1);
        string ans ="";
        
        int cnt = 1 ;
        int j = 0 ;
        for(int i = 1 ; i < say.length() ; i++){
               if(say[i] == say[j])
                   cnt++;
               else{
                   
                   ans += to_string(cnt) + say[j];
                   cnt = 1;
                   j = i;
               }
            
        }
        if(cnt > 0){
             ans += to_string(cnt) + say[j];
        }
        return ans;
        
    }
};