class Solution {
public:
	int helper(string start,string end,unordered_set<string> &st){
		  queue<pair<string,int>> q;
		  q.push({start,1});  //current string and length 
		  while(!q.empty()){
			  int n=q.size();
			  while(n--)
			  {
				  string temp=q.front().first;
				  int len=q.front().second;
				  q.pop();
				  if(temp==end) return len; 
				  for(int j=0;j<temp.length();j++){
						string curr=temp;
					  for(int i=0;i<26;i++){
						  curr[j]=i+'a';
						  // cout<<curr<<" ";
						  if(curr!=temp && st.find(curr)!=st.end()){ 
							   q.push({curr,len+1});
							  st.erase(curr);
						  }
					  }
				  }
			  }
		  }
		return 0;
	}
	int ladderLength(string start, string end, vector<string>& wordList) {
		 unordered_set<string> st;
		 for(auto &word: wordList) st.insert(word); //for making searching faster
		 if(st.find(end)==st.end()) return 0;

		 return helper(start,end,st);

	}
};