class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<pair<int,int>,int> mp;

        for(auto&i:words){
            mp[{i[0]-'a',i[1]-'a'}]++;
        }

        int ans=0;
        bool fl=1;
        for(auto&i:mp){
            if(i.first.first!=i.first.second){
                ans+=4*min(i.second,mp[{i.first.second,i.first.first}]);
                mp[{i.first.second,i.first.first}]=0;
                mp[{i.first.first,i.first.second}]=0;
            }
            else{
                ans+=2*(i.second/2*2);
                if(i.second&1){
                    if(fl) ans+=2;
                    fl=0;
                }
            }
        }

        return ans;
    }
};