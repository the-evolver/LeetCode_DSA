class Solution {
public:
    int minPartitions(string n) {
        int max = -1;
        int len = n.length();
        for(int i = 0 ; i < len ; i++){
            if(n[i] - '0' > max){
                max = n[i] - '0';
            }
        }
        return max;
    }
};