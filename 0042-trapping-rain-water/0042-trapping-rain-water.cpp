class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int mx=*max_element(h.begin(),h.end());
        int id=0;

        for(int i=0;i<n;i++){
            if(h[i]==mx){
                id=i;
                break;
            }
        }

        int prev=0;
        int ans=0;
        for(int i=0;i<id;i++){
            prev=max(prev,h[i]);
            ans+=prev;
            ans-=h[i];
        }

        prev=0;
        for(int i=n-1;i>id;i--){
            prev=max(prev,h[i]);
            ans+=prev;
            ans-=h[i];
        }

        return ans;
    }
};