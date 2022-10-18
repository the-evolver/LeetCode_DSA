class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<int> help(n+1,1);
        for(int i = 3 ; i <= n ; i = i + 3){
            help[i] *= 3;
        }
        for(int i = 5 ; i <= n ; i = i + 5){
             help[i] *= 5;
        }
        
        vector<string> ans(n);
        for(int i = 1 ; i <= n ; i++){
            if(help[i] == 15){
                ans[i-1] = "FizzBuzz";
            }
            if(help[i] == 5){
                ans[i-1] = "Buzz";
            }
            if(help[i] == 3){
                ans[i-1] = "Fizz";
            }
            if(help[i] == 1){
                ans[i-1] = to_string(i);
            }
        }
        return ans;
        
    }
};