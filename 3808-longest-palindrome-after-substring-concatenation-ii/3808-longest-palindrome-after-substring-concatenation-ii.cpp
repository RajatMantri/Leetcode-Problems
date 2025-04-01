#define ll long long
#define f first
#define s second

const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
 
const int N=1e3+1;
ll p=31,q=41;

 
ll ppp[N];
ll qqq[N];
 
ll power(ll a, ll b,ll mod){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(a*res)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
}
 
pair<ll,ll> getHash1(vector<pair<ll,ll>>&h,int l,int r){
    ll inv1=ppp[l];
    ll inv2=qqq[l];
 
    if(l==0){
        ll a=h[r].f*inv1,b=h[r].s*inv2;
        return {a<mod1?a:a%mod1,b<mod2?b:b%mod2};
    }
 
    ll a=(h[r].f-h[l-1].f),b=(h[r].s-h[l-1].s);
    if(a<0) a+=mod1;
    if(b<0) b+=mod2;
 
    return {(a*inv1)<mod1?a*inv1:a*inv1%mod1,(b*inv2)<mod2?b*inv2:b*inv2%mod2};
}
 
pair<ll,ll> getHash2(vector<pair<ll,ll>>&h,int l,int r){
    int n=h.size();
    ll inv1=ppp[n-r-1];
    ll inv2=qqq[n-r-1];
 
    if(r==n-1){
        ll a=h[l].f*inv1,b=h[l].s*inv2;
        return {a<mod1?a:a%mod1,b<mod2?b:b%mod2};
    }
 
    ll a=(h[l].f-h[r+1].f),b=(h[l].s-h[r+1].s);
    if(a<0) a+=mod1;
    if(b<0) b+=mod2;
 
    return {(a*inv1)<mod1?a*inv1:a*inv1%mod1,(b*inv2)<mod2?b*inv2:b*inv2%mod2};
}

bool check(vector<pair<ll,ll>>&h,vector<pair<ll,ll>> &ss,int i,int j){
    int len=(j-i+1);
    if(len&1){
        if(getHash1(h,i,i+len/2)==getHash2(ss,i+len/2,i+len-1)) return 1;
        return 0;
    }
    else{
        if(getHash1(h,i,i+len/2-1)==getHash2(ss,i+len/2,i+len-1)) return 1;
        return 0;
    }
}

class Solution {
public:
    int longestPalindrome(string ss, string t) {
        int n=ss.length(),m=t.length();
        
        ppp[0]=power(1,mod1-2,mod1);
        qqq[0]=power(1,mod2-2,mod2);
        ll aa=p,bb=q;

        for(int i=1;i<N;i++){
            ppp[i]=power(aa,mod1-2,mod1);
            qqq[i]=power(bb,mod2-2,mod2);

            aa*=p,bb*=q;
            aa%=mod1,bb%=mod2;
        }

        vector<pair<ll,ll>> hash(n);
        vector<pair<ll,ll>> suff(m);
        vector<pair<ll,ll>> hash1(m);
        vector<pair<ll,ll>> suff1(n);
        
        hash[0]={ss[0]-'a'+1,ss[0]-'a'+1};
        hash1[0]={t[0]-'a'+1,t[0]-'a'+1};
        suff1[n-1]={ss[n-1]-'a'+1,ss[n-1]-'a'+1};
        suff[m-1]={t[m-1]-'a'+1,t[m-1]-'a'+1};

        ll pp=1,qq=1;

        for(int i=1;i<n;i++){
            pp*=p,qq*=q;
            pp%=mod1,qq%=mod2;
            ll val=ss[i]-'a'+1;

            hash[i].f=(hash[i-1].f+pp*val)%mod1;
            hash[i].s=(hash[i-1].s+qq*val)%mod2;
        }

        pp=1,qq=1;

        for(int i=m-2;i>=0;i--){
            pp*=p,qq*=q;
            pp%=mod1,qq%=mod2;
            ll val=t[i]-'a'+1;

            suff[i].f=(suff[i+1].f+pp*val)%mod1;
            suff[i].s=(suff[i+1].s+qq*val)%mod2;
        }
        
        pp=1,qq=1;
        
        for(int i=1;i<m;i++){
            pp*=p,qq*=q;
            pp%=mod1,qq%=mod2;
            ll val=t[i]-'a'+1;

            hash1[i].f=(hash1[i-1].f+pp*val)%mod1;
            hash1[i].s=(hash1[i-1].s+qq*val)%mod2;
        }

        pp=1,qq=1;

        for(int i=n-2;i>=0;i--){
            pp*=p,qq*=q;
            pp%=mod1,qq%=mod2;
            ll val=ss[i]-'a'+1;

            suff1[i].f=(suff1[i+1].f+pp*val)%mod1;
            suff1[i].s=(suff1[i+1].s+qq*val)%mod2;
        }

        int cc=mod2+2;
        
        unordered_map<ll,int> mp;
        int ans=1;
        
        for(int j=n-1;j>=1;j--){
            int i=0;
            pair<ll,ll> h=getHash1(hash,i,(i+j-1)/2);
            pair<ll,ll> s=getHash2(suff1,(i+j)/2+1,j);

            if(h==s){
                ans=max(ans,j-i+1);
                break;
            }
        }
        
        for(int i=0;i<m-1;i++){
            int j=m-1;
            pair<ll,ll> h=getHash1(hash1,i,(i+j-1)/2);
            pair<ll,ll> s=getHash2(suff,(i+j)/2+1,j);

            if(h==s){
                ans=max(ans,j-i+1);
                break;
            }
        }
        
        vector<int> pal1(n);
        vector<int> pal2(m);
        
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                if(check(hash,suff1,i+1,j)){
                    pal1[i]=j-i;
                    break;
                }
            }
            ans=max(ans,pal1[i]);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(check(hash1,suff,j,i-1)){
                    pal2[i]=i-j;
                    break;
                }
            }
            ans=max(ans,pal2[i]);
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pair<ll,ll> h=getHash1(hash,i,j);
                ll hh=h.f+h.s*cc;
                if(mp.count(hh)==0) mp[hh]=pal1[j];
                else mp[hh]=max(mp[hh],pal1[j]);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                pair<ll,ll> p=getHash2(suff,i,j);
                ll pc=p.f+p.s*cc;
                if(mp.count(pc)){
                    int curr=2*(j-i+1);
                    int curr1=pal2[i];
                    ans=max(ans,curr+curr1);
                    int curr2=mp[pc];
                    ans=max(ans,curr+curr2);
                }
            }
        }
        
        return ans;
    }
};