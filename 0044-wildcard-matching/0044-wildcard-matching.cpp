class Solution {
public:

    bool f(int i,int j,string&s,string&p,vector<vector<int>> &dp){
        if(j==p.length()) return i==s.length();
        if(i==s.length()){
            while(j<p.length()) if(p[j++]!='*') return false;
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j]||p[j]=='?') return dp[i][j]=f(i+1,j+1,s,p,dp);
        else if(p[j]=='*') return dp[i][j]=f(i+1,j,s,p,dp)|f(i+1,j+1,s,p,dp)|f(i,j+1,s,p,dp);
        else return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,s,p,dp);
    }
};