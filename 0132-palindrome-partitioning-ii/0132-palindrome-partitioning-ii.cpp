class Solution {
public:
    bool check(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int dp[2001];
    int f(string& s,int prev){
        if(prev==s.length()) return 0;

        if(dp[prev]!=-1) return dp[prev];

        int ans=INT_MAX;

        for(int i=prev;i<s.length();i++){
            if(check(s,prev,i)){
                ans=min(ans,1+f(s,i+1));
            }
        }

        return dp[prev]=ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return f(s,0)-1;
    }
};