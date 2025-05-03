class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=1e9;
        map<int,int> mp;
        int n=tops.size();

        vector<int> poss;

        for(int i=0;i<n;i++){
            mp[tops[i]]++;
            if(tops[i]!=bottoms[i]) mp[bottoms[i]]++;

            if(mp[tops[i]]==n) poss.push_back(tops[i]);
            if(mp[bottoms[i]]==n&&bottoms[i]!=tops[i]) poss.push_back(bottoms[i]);
        }

        for(auto&i:poss){
            int res1=0,res2=0;

            for(int j=0;j<n;j++){
                if(tops[j]!=i) res1++;
            }

            for(int j=0;j<n;j++){
                if(bottoms[j]!=i) res2++;
            }

            ans=min(res1,res2);
        }

        if(ans==1e9) ans=-1;

        return ans;
    }
};