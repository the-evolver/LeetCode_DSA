class Solution {
public:
    double myPow(double x, long long n) {
        
        if( n == 0)
            return 1.0;
        if( n < 0)
            return ((long long) 1/myPow(x,-n));
        
        if(n % 2 == 0)
            return myPow(x*x,n/2);
        
        // else if n odd
        return myPow(x*x,n/2)*x;
        
    }
        
};