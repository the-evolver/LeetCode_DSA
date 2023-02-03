class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int low = 0 , high = n - 1;
        
        while( low < high  ){
               cout<<low<<"  "<<high<<endl;
               int mid = (low + high)/2;
            
               if(arr[mid] < arr[mid+1])
                   low = mid + 1;
               else
                   high = mid;
            
            
        }
        //cout<<low<<endl;
        
        
        return low;
    }
};