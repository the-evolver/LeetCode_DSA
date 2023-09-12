class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1 , carry = 0;
        int n = digits.size();
        for(int i = n - 1 ; i >= 0 ; i--){
             
            int num = digits[i] + carry + add;
            digits[i] = num % 10;
            carry = num / 10;
            add = 0;
            
        }
        
        if( carry > 0 ){
            digits.push_back(-1);
            for(int i = n - 1 ; i >= 0 ; i--){
             
               digits[i+1] = digits[i];
            
            }
            digits[0] = carry;
        }
        return digits;
        
    }
};