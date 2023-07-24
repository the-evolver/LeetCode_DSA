class Solution {
    
        public List<Boolean> camelMatch(String[] queries, String pattern) {
         List<Boolean> result=new ArrayList<>();
         for(String query:queries){
             int index=0;
             boolean res=true;
             for(int i=0;i<query.length();i++){
               if(index < pattern.length() && query.charAt(i) == pattern.charAt(index)){
               index++;
               continue;
            }
            if(query.charAt(i) >= 65 && query.charAt(i) <= 90){
               if(index >= pattern.length() || query.charAt(i) != pattern.charAt(index)){
                  res = false;
                  break;
               }
            }
         }
         res = res && index == pattern.length();
         result.add(res);
      }
      return result;
    }
             
        
    }
