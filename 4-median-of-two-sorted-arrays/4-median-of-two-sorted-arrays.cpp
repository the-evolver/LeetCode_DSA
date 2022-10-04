class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        
        if((m + n  ) % 2 == 0){
            int indx = (m + n) / 2 ;
            int cnt = 0;
            int l1 = 0;
            int l2 = 0;
            
            while(l1 < n && l2 < m && cnt <= indx){
                
                 if(nums1[l1] < nums2[l2]){
                     if(cnt == indx - 1 || cnt == indx ){
                         ans += nums1[l1];
                         
                         
                     }
                     l1++;
                     cnt++;
                     
                 }else{
                     if(cnt == indx - 1 || cnt == indx ){
                         ans += nums2[l2];
                         
                         
                     }
                     l2++;
                     cnt++;

                 
                 
                 
                 }
            }
                
                if(cnt <= indx ){
                    while(l1 < n ){
                        if(cnt == indx - 1 || cnt == indx ){
                         ans += nums1[l1];
                            
                        
                        
                         
                     }
                        l1++;
                        cnt++;
                        
                        
                    }
                    while(l2 < m ){
                        if(cnt == indx - 1 || cnt == indx ){
                         ans += nums2[l2];
                         
                         
                     }
                         l2++;
                         cnt++;
                        
                        
                    }
                    
                    
                    
                }
             return (ans/2);                
            }else{
            
            int indx = (m + n) / 2 ;
            int cnt = 0;
            int l1 = 0;
            int l2 = 0;
            
            while(l1 < n && l2 < m && cnt <= indx){
                 if(nums1[l1] < nums2[l2]){
                     if( cnt == indx ){
                         ans += nums1[l1];
                         
                         
                     }
                     cnt++;
                     l1++;
                 }else{
                     if( cnt == indx ){
                         ans += nums2[l2];
                         
                         
                     }

                 cnt++;
                 l2++;
                 
                 
                 }
            }
                
                if(cnt <= indx ){
                    while(l1 < n && cnt <= indx){
                        if( cnt == indx ){
                         ans += nums1[l1];
                         
                         
                     }
                        cnt++;
                        l1++;
                        
                    }
                    while(l2 < m && cnt <= indx){
                        if( cnt == indx ){
                         ans += nums2[l2];
                       
                         
                     }
                        cnt++;
                        l2++;
                        
                    }
                    
                    
                    
                }
                
            }
            
            
            return ans;
        
        
    }
};