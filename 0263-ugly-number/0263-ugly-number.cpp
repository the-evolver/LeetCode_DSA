class Solution {
public:
    
    
    bool isUgly(int n) {
        if( n <= 0)
            return false;
        
        
        while( n % 2 == 0)
            n = n/2;
        
        while( n % 3 == 0)
            n = n/3;
        
        while( n % 5 == 0)
            n = n/5;
        
        return n == 1;
        
//         if(n <= 0 )
//             return false;
        
//         vector<int> primes(n+1,false);
//         primes[0] = primes[1] = true;
        
//         for(int i = 2 ; i * i <= n ; i++){
             
//             if(primes[i] == false){
                
//                 for(int j = i * i ; j <= n ; j = j + i )
//                      primes[j] = true;
                
//             }
            
//         }
//         for(int i = 0 ; i <= n ; i++){
//              if(primes[i] == false && n % i == 0 && i != 2 && i != 3 && i != 5)
//                  return false;
//         }
    
        
//        return true;
        
    }
    
   
};