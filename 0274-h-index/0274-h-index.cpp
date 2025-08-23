class Solution {
public:
    bool ch(vector<int>&c,int m){
        int cc=0;
        for(auto&i:c){
            if(i>=m) cc++;
        }

        return cc>=m;
    }
    int hIndex(vector<int>& c) {
        int n=c.size();

        int l=0,r=n;
        int ans=0;

        while(l<=r){
            int mid=(l+r)/2;

            if(ch(c,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};