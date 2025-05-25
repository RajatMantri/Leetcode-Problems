class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.size();

        vector<int> vis(26,-1);
        int ans=0;

        for(int i=0;i<n;i++){
            int num=word[i]-'a';

            if(vis[num]==-1){
                vis[num]=i;
                continue;
            }

            if(i-vis[num]>=3){
                ans++;
                for(auto&j:vis) j=-1;
            }
        }

        return ans;
    }
};