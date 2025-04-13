#define ll unsigned long long
ll ncr(int n, int r){
    ll p=1,k=1;
    if(r>n) return 0;
    if(n-r<r) r=n-r;
 
    if(r!=0){
        for(int i=1;i<=r;i++){
            p*=n;
            p/=i;
            n--;
        }
    }
    
    return p;
}
class Solution {
public:
    ll ff(vector<int> &f){
        ll t=0;
        ll ans=1;
        for(auto&i:f){
            t+=i;
        }
        for(auto&i:f){
            if(i>0){
                ans*=ncr(t,i);
                t-=i;
            }
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> f(26); 
        vector<int> g(26); 
        for(auto&i:s) f[i-'a']++,g[i-'a']++;
        for(int i=0;i<26;i++) f[i]/=2;

        string fr;
        k--;

        while(k){
            bool ch=0;
            for(int j=0;j<26;j++){
                if(f[j]){
                    f[j]--;
                    if(ff(f)>k){
                        fr.push_back(j+'a');
                        ch=1;
                        break;
                    }
                    k-=ff(f);
                    f[j]++;
                }
            }
            if(ch==0) return "";
        }

        for(int i=0;i<26;i++){
            while(f[i]){
                fr.push_back(i+'a');
                f[i]--;
            }
        }

        string bk=fr;
        reverse(bk.begin(),bk.end());

        for(int j=0;j<26;j++) if(g[j]&1) fr.push_back(j+'a');
        fr.append(bk);

        return fr;
    }
};