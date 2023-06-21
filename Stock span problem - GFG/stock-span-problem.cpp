//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ngleft(n,-1);
       
       stack<int> st;
       
       for(int i = n - 1 ; i >= 0 ; i--){
           if(st.size() == 0){
               st.push(i);
           }else{
               
               while(st.size() > 0 && price[i] > price[st.top()]){
                      ngleft[st.top()] = i;
                      st.pop();
               }
               
               st.push(i);
               
           }
       }
       vector<int> ans(n,0);
       for(int i = 0 ; i < n ; i++){
           if(ngleft[i] == -1){
               ans[i] = i+1;
           }else{
               ans[i] = i - ngleft[i];
           }
       }
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends