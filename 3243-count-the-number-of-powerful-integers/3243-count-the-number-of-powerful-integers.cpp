#define ll long long
class Solution {
public:
    ll dp[17][2];
    ll f(int limit,string&s,string&num,int i,bool tight){
        if(i==s.length()-num.length()){
            if(!tight) return 1;
            else{
                for(int j=i;j<s.length();j++){
                    if(s[j]>num[j-i]) return 1;
                    if(s[j]<num[j-i]) return 0;
                }
                return 1;
            }
        }

        if(dp[i][tight]!=-1) return dp[i][tight];

        int ub=limit;
        if(tight) ub=min(limit,s[i]-'0');

        ll ans=0;

        for(int j=0;j<=ub;j++){
            ans+=f(limit,s,num,i+1,tight&&(ub==j)&&(s[i]-'0'<=limit));
        }

        return dp[i][tight]=ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string ss,pp;
        ss=to_string(start-1);
        pp=to_string(finish);

        ll lf=0;
        memset(dp,-1,sizeof(dp));
        if(s.length()<=ss.length()) lf=f(limit,ss,s,0,1);
        ll rt=0;
        memset(dp,-1,sizeof(dp));
        if(s.length()<=pp.length()) rt=f(limit,pp,s,0,1);

        return rt-lf;
    }
};