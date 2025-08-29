static auto speedup = []()  {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
    bool solve(vector<int>& piles,int mid,int h){
        int count=0;
        for(int i=0;i<piles.size();i++){
            int element=piles[i];
            count+=(element+mid-1)/mid;
            if(count>h) return false;
        }
        return true;
       }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int s=1,e= *max_element(piles.begin(), piles.end());
        int ans=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(solve(piles,mid,h)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};