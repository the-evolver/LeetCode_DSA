/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        long long  st = 0 , en = n , mid;
        while(st <= en){
            mid = (st + en )/2;
            int v = guess(mid);
            if(v == 0)
                return mid;
            if(v == 1){
                st = mid + 1;
            }
            if(v == -1)
                en = mid-1;
        }
        return 0;
    }
};