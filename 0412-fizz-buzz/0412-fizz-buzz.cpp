class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        int cnt3 = 0 , cnt5 = 0;
        
         vector<string> ans;
        
         for(int i = 1 ; i <= n ; i++){
                  cnt3++;
                  cnt5++;
                  string curr ="";
             
                 if(cnt3 == 3){
                      curr += "Fizz";
                      cnt3 = 0;
                 }
                 if(cnt5 == 5){
                     curr += "Buzz";
                     cnt5 = 0;
                 }
             
             if(curr == ""){
                 curr = to_string(i);
             }
                
             ans.push_back(curr);
             
             
         }
        return ans;
        
    }
};