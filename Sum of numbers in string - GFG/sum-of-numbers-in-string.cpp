//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	int total_sum = 0;
    	int curr_sum = 0;
    	
    	for(int i = 0 ; i < str.length() ; i++){
    	     if(str[i] > 57){
    	         total_sum += curr_sum;
    	         curr_sum = 0;
    	         
    	     }else{
    	         curr_sum = curr_sum * 10 + (str[i] - '0');
    	         
    	     }
    	}
    	total_sum += curr_sum;
    	curr_sum = 0;
    	
    	return total_sum;
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends