class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        int f1 = 0 , f2 = 1;
        int curr = f1 + f2 ;
        for(int i = 2 ; i <= n ; i++){
            curr = f1 + f2 ;
            f1 = f2;
            f2 = curr;
        }
        return curr;
    }
};