//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     for(int i = 0 ; i < s.length() ; i++){
           
            if(s[i] == x[0]){
                int k = i;
                int j = 0;
                 for(; j < x.length() && k < s.length() ;){
                       if(s[k] == x[j]){
                           j++;
                           k++;
                       }else{
                           break;
                       }
                 }
                 if(j == x.length())
                  return i;
                 
                 
            }
           
     }
     return -1;
}