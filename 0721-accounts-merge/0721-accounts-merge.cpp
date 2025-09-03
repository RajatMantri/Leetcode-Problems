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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mail;
        vector<vector<string>> ans;
        int n=accounts.size();
        dsu d(n);
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mail.find(accounts[i][j])==mail.end()) mail[accounts[i][j]]=i;
                else d.unionsize(i,mail[accounts[i][j]]);
            }
        }
        unordered_map<int,vector<string>> mp;
        for(auto&i:mail){
            int node=i.second;
            mp[d.findPar(node)].push_back(i.first);
        }

        for(auto&i:mp){
            sort(i.second.begin(),i.second.end());
            ans.push_back({accounts[i.first][0]});
            for(auto&j:i.second){
                ans.back().push_back(j);
            }
        }

        return ans;
    }
};