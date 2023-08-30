class Solution {
    public int candy(int[] ratings) {
        int len=ratings.length;
        if(len==0){
            return 0;
        }
        int sum=1;
        int i=1;
        int amount=1;
        int peek_pre_amount=0;
        while(i<len){
            while(i<len && ratings[i-1]<=ratings[i]){
                amount++;
                if(ratings[i-1]==ratings[i]){
                    amount=1;
                }
                sum+=amount;
                i++;
            }
            peek_pre_amount=amount;
            boolean first=true;
            amount=1;
            if(i==len){
                break;
            }
            while(i<len && ratings[i-1]>=ratings[i]){
                amount++;
                if(ratings[i-1]==ratings[i]){
                    if(first){
                        sum-=(peek_pre_amount<(amount-1))?peek_pre_amount:amount-1;
                        sum+=1;
                        first=false;
                    }
                    amount=1;
                }
                sum+=amount;
                i++;
            }
            if(first){
                sum-=(peek_pre_amount<amount)?peek_pre_amount:amount;
                sum+=1;
            }
            amount=1;
            if(i==len){
                break;
            } 
        }
        return sum;
    }
}