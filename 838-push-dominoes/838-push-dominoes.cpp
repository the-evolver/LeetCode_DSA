class Solution {
public:
    string pushDominoes(string dominoes) {
        
        string dom(dominoes);
        
        int n = dominoes.length();
        
        int indx[n+2];
        char symb[n+2];
        indx[0] = -1;
        symb[0] = 'L';
        int curr_i = 1;
       
        for(int i = 0 ; i < n;i++){
              if(dom[i] != '.' ){
                  indx[curr_i] = i;
                  symb[curr_i] = dom[i];
                  curr_i++;
              }
            
                 
        }
        indx[curr_i] = n + 1;
        symb[curr_i] = 'R';
        curr_i++;
        
        for(int i = 0 ; i < curr_i - 1 ; i++){
             char st = symb[i];
             char en = symb[i+1];
             int si = indx[i] + 1;
             int ei = indx[i+1] - 1;
            
         if(st == 'L' && en == 'L'){
                  for(int j = si ; j <= ei ; j++){
                      dom[j] = 'L';
                  }
             
         }
         else if(st == 'R' && en == 'R'){
             for(int j = si ; j <= ei ; j++){
                      dom[j] = 'R';
                  }
             
         }
         else if(st == 'L' && en == 'R'){
             
         }
         else if(st == 'R' && en == 'L'){
             
             // cout<<si<<" --- "<<ei<<endl;
                 for(int j1 = si , j2 = ei ; j1 < j2 ; j1++,j2--){
                     dom[j1] = 'R';
                     dom[j2] = 'L';
                 }
                      
             
             
         }
            
            
             
        }
        
        
        
        
        return dom;
        
        
        //return dom.substr(1,dom.length()-2);
        
    }
//     string segment(string dom,int si,int ei , char st , char en){
//               if(st == 'L' && en == 'L'){
//                   for(int j = si ; j <= ei ; j++){
//                       dom[j] = 'L';
//                   }
             
//          }
//          else if(st == 'R' && en == 'R'){
//              for(int j = si ; j <= ei ; j++){
//                       dom[j] = 'R';
//                   }
             
//          }
//          else if(st == 'L' && en == 'R'){
             
//          }
//          else if(st == 'R' && en == 'L'){
             
//              // cout<<si<<" --- "<<ei<<endl;
//                  for(int j1 = si , j2 = ei ; j1 < j2 ; j1++,j2--){
//                      dom[j1] = 'R';
//                      dom[j2] = 'L';
//                  }
                      
             
             
//          }
//         return dom;

//     }
    
    /* segments :
           L ..... L
           R ..... R
           L ..... R
           R ..... L
    */
};