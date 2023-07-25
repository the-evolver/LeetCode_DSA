class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int st = 0 , en = n-1 , mid;
        
        while(st <= en){
            mid = (st + en + 1)/2;
            if(mid == 0 || mid == n - 1)
                return -1;
            
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            
            
            if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1])
                st = mid + 1;
            
            
            if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1])
                en = mid - 1;
            
            
        }
        return -1;
        
    }
};