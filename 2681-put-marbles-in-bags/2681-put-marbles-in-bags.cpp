#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        
        priority_queue<int> p;
        priority_queue<int> q;

        for(int i=0;i<n-1;i++) p.push(weights[i]+weights[i+1]),q.push(-weights[i]-weights[i+1]);
        
        ll ans=0;

        while(--k){
            ans+=p.top()+q.top();
            p.pop(),q.pop();
        }

        return ans;
    }
};