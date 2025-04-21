class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int res=0,n=ans.size();

        vector<int> mp(1001);

        for(int i=0;i<n;i++){
            mp[ans[i]]++;
        }

        for(int i=0;i<=1000;i++){
            if(mp[i]>0){
                res+=(mp[i]+i)/(i+1)*(i+1);
            }
        }

        return res;
    }
};