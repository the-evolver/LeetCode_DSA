class Solution {
public:
    unordered_map<int,string> up;
    string intToRoman(int num) {
        
        up[5]    ="V";
        up[10]   ="X";
        up[50]   ="L";
        up[100]  ="C";
        up[500]  ="D";
        up[1000] ="M";
        
        return comp(num);
    }
    
    string comp(int num){
        if(num == 0)
            return "";
        if(num == 1){
            return "I";
        }
        if(num == 2)
            return "II";
        if(num == 3){
            return "III";
        }
        if(num == 4){
            return "IV";
        }
        if(num == 9){
            return "IX";
        }
        if(num >= 40 && num < 50){
            return "XL"+comp(num-40);
            
        }
        if(num >= 90 && num < 100){
            return "XC" + comp(num - 90);
        }
        if(num >= 400 && num < 500){
            return "CD" + comp(num - 400);
        }
        if(num >= 900 && num < 1000){
            return "CM" + comp(num - 900);
        }
        
        int arr[] = {5,10,50,100,500,1000};
        int i = 0;
        for( ; i <= 5 ; i++){
             if(arr[i] > num)
                 break;
        }
        
        int val = arr[i-1];
        return up[val] + comp(num-val);
    }
};