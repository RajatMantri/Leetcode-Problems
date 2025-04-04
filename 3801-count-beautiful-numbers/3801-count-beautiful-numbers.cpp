class Solution {
public:
    string ff(int j,bool tight,bool lead,int pro,int sum){
        return to_string(j)+":"+to_string(tight)+":"+to_string(lead)+":"+to_string(pro)+":"+to_string(sum);
    }
    int f(int j,bool tight,bool lead,int pro,int sum,string &s,unordered_map<string,int>&dp){
        if(j==s.length()){
            if(sum==0) return 0;
            return (pro%sum)==0;
        }

        string ss=ff(j,tight,lead,pro,sum);
        if(dp.find(ss)!=dp.end()) return dp[ss];

        int ub=9;
        if(tight) ub=s[j]-'0';

        int ans=0;

        for(int i=0;i<=ub;i++){
            if(lead==1){
                if(i>0) ans+=f(j+1,tight&(ub==i),0,i,sum+i,s,dp);
                else ans+=f(j+1,tight&(ub==i),1,pro,sum+i,s,dp);
            }
            else{
                ans+=f(j+1,tight&(ub==i),0,pro*i,sum+i,s,dp);
            }
        }

        return dp[ss]=ans;
    }

    int beautifulNumbers(int l, int r) {
        string lf=to_string(l-1);
        string rf=to_string(r);
        unordered_map<string,int> dp1;
        unordered_map<string,int> dp2;
        return f(0,1,1,0,0,rf,dp1)-f(0,1,1,0,0,lf,dp2);
    }
};