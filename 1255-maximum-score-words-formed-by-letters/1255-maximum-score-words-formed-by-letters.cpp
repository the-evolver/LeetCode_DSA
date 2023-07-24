class Solution {
public:
    int dp[(1<<14)+10];
    int n;
    int rec(int mask,vector<int>&mp,vector<string>& words,vector<int>& score){
        if(mask==((1<<n)-1)) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int ans=0;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))){
                int fr[26]={};
                for(auto j:words[i]) fr[j-'a']++;
                bool flag=true;
                for(int j=0;j<26;j++){
                    if(fr[j]>0){
                        if(mp[j]>=fr[j]) continue;
                        else{flag=false;break;}
                    }
                   
                }
                if(!flag)continue;
                int cor=0;
                for(int j=0;j<26;j++){
                    if(fr[j]>0) {mp[j]-=fr[j];cor+=(fr[j]*score[j]);}
                }
                
                ans=max(ans,cor+rec(mask|(1<<i),mp,words,score));
                for(int j=0;j<26;j++){
                    if(fr[j]>0)mp[j]+=fr[j];
                }
            }
        }
        return dp[mask]=ans;
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        memset(dp,-1,sizeof(dp));
        n=words.size();
        vector<int> mp(26,0);
        for(auto c:letters){
            mp[c-'a']++;
        }
        return rec(0,mp,words,score);
    }
};