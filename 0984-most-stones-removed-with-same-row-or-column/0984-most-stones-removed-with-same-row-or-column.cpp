class dsu{
    vector<int> parent;
    vector<int> size;
    
    public:
    dsu(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        size.resize(n+1,1);
    }
    
    int findPar(int u){
        if(parent[u]==u) return u;
        parent[u]=findPar(parent[u]);
        return parent[u];
    }
    
    void unionsize(int u,int v){
        int V=findPar(v);
        int U=findPar(u);
        
        if(V==U) return;
        if(size[V]>size[U]){
            parent[U]=V;
            size[V]+=size[U];
        }
        else{
            parent[V]=U;
            size[U]+=size[V];
        }
    }
    
    void reset(int u){
        parent[u]=u;
        size[u]=1;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        dsu d(20002);
        for(auto&e:stones){
            d.unionsize(e[0],e[1]+10001);
        }

        unordered_set<int> s;
       // s.insert(d.findPar(stones[0][0]));

        for(int i=0;i<stones.size();i++){
            //if(d.findPar(stones[i][0])!=d.findPar(stones[0][0])) 
            s.insert(d.findPar(stones[i][0]));
        }

        return stones.size()-s.size();
    }
};