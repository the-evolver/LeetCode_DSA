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
        
        long  st = 1 , en = n ;
        long mid;
        while(st <= en){
            mid = (st + en )/2;
            
            int val = guess(mid);
            if(val < 0){
                en = mid - 1;
            }
            else if(val > 0)
                st = mid + 1;
            else
                return mid;
        }
        return -1;
        
    }
};