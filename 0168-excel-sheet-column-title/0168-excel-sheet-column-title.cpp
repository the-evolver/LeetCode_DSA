class Solution {
public:
    string convertToTitle(int n) {
        string str ="";
        
        while(n){
            n--;
            int k = n % 26;
            str +='A'+k;
            n/=26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};