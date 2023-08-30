class Solution {
    public String getPermutation(int n, int k) {
        
        StringBuilder temp = new StringBuilder(); 
        for( int i = 1 ; i <= n ; i++)
        {
            temp.append(i); 
        }
        StringBuilder str = new StringBuilder() ;
        return helper( temp , str ,  k-1) ;  
    }
    public String helper( StringBuilder temp , StringBuilder str , int k )
    {    
        if( temp.length() == 1)
         {
             str.append(temp.charAt(0)) ; 
             return str. toString() ;
         }
           int value = factorial(temp.length()-1) ; 
           int quotient = k / value ;  
           int remainder = k % value ;
           str.append(temp.charAt(quotient)) ; 
           temp.deleteCharAt(quotient) ; 
           return helper(temp , str , remainder) ;
    }
    public int factorial( int number)
    {
        int value = 1 ; 
        for( int i = 1 ; i <= number ; i++)
        {
            value *= i ; 
        }
        return value ;
    }
}