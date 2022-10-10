class Solution {
public:
    double myPow(double x, int n) {
        
        double val = 1;
        long long num = n;
        long long int cnt = num > 0 ? num :(long)-num;
        while(cnt > 0){
            if(cnt % 2 != 0){
                val = val * x;
               
                
            }
             x = x* x;
             cnt = cnt /2;
            
            
        }
        if(n < 0){
            double ans = (1/val);
            return ans;
        }
        return val;
        
    }
};