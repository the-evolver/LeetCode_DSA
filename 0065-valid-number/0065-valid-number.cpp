
class Solution {
public:
    bool isNumber(string s) {
        bool flag = false;
        bool sflag = false;
        int eflag = 0;
        if(s[s.length()-1] == 'e' | s[0] == 'e' | s[0] == 'E'| s[s.length()-1] == 'E'  | s[s.length()-1] == '-' | s[s.length()-1] == '+' )return false;
        if(s == "e" || s == "E" || s == "." || s == "+" || s == "-" ) return false;
        for(int i = 0 ; i<s.length();i++){
            if(s[i] == 'e' | s[i] == 'E' | s[i] == '+' | s[i] == '-' | s[i] == '.' | isdigit(s[i])){
                if(s[i] == '+' | s[i] == '-'  ){
                    if(s.length()>2){
                        if(s[i+1] == '.')
                            if(!isdigit(s[i+2]))
                                return false;
                        if(s[i+1] =='e'| s[i+1]=='E')return false;
                    }
                    if(s.length()==2)
                        if(s[1] == '.' | s[1] == '-' | s[1] == '+')return false;
                    if(i!=0){
                        if(isdigit(s[i-1]))return false;
                    }  
                }
                if(s[i] == '+' )
                     sflag = true;
                
                if(s[i] == '-')
                    if(sflag)return false;
                if(s[i] == '.'){
                    if(eflag>0)return false;
                    if(s.length()>2){
                        if(i==0)
                            if(s[i+1] == 'e' | s[i+1] == 'E')return false;
                        if(s[i+1] == '-' || s[i+1] == '+' )return false;
                    }
                    if(flag)return false;
                    flag = true;
                }
                if(s[i] == 'e'){
                    eflag++;
                    if(s[i+1] == '.' | s[i+1] == 'E' | s[i+1] == 'e') return false;
                }
                if(eflag>1)return false;
            }else
                return false;
        }
        return true;
    }
};