#define pp pair<int,int>
static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int S) {
        vector<int> dist(n+1,1e9);
        dist[S]=0;

        vector<pair<int,int>> adj[n+1];
        for(auto&i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        set<pp>p;
        p.insert({0,S});
        
        while(!p.empty()){
            auto it=p.begin();
            int node=(*it).second;
            p.erase(it);
            
            for(auto&k:adj[node]){
                int wt=k.second;
                int adjnode=k.first;
                if(dist[adjnode]>dist[node]+wt){
                    p.erase({dist[adjnode],adjnode});
                    dist[adjnode]=dist[node]+wt;
                    p.insert({dist[adjnode],adjnode});
                }
            }
        }

        int cost=INT_MIN;

        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            else cost=max(cost,dist[i]);
        }
        
        return cost;
    }
};