class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        while(left > 0 && right > 0){
            int msbLeft = msbPosition(left);
            int msbRight = msbPosition(right);
            
            //If the msb's position of left and right range don't match then return
            if(msbLeft != msbRight){
                break;
            }
            
            //Add 2^msbPostion to ans
            int msbVal = (1 << msbLeft);
            ans+=msbVal;
            
            //Substraact current msbVal from left and right
            left = left - msbVal;
            right = right - msbVal;
        }
        return ans;
    }
    
    //Method to get the posion of MSB of a number
    public static int msbPosition(int n){
        int pos = -1;
        while(n > 0){
            n = n >> 1;
            pos++;
        }
        return pos;
    }
}