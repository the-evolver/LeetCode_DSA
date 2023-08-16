class Solution {
    public int largestPalindrome(int n) {
        
        if(n == 1) return 9;
        long max_val = (long)Math.pow(10, n) - 1;
        long min_val = max_val / 100;
        for (long lf = max_val; lf > min_val; lf--) {
            long rt = Long.parseLong(new StringBuilder("" + lf).reverse().toString());
            long l_val = lf * (max_val + 1) + rt;
            for (long i = max_val; i * i >= l_val; i--) {
                if (l_val % i == 0) {
                    return (int)(l_val % 1337);
                }
            }
        }
        return -1; // temporal dead zone ... 
    }
}