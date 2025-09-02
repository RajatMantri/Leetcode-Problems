class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<int> in(n);
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<n;i++){
            for(auto&j:adj[i]) in[j]++;
        }

        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);

            for(auto&node:adj[curr]){
                in[node]--;
                if(in[node]==0) q.push(node);
            }
        }

        if(ans.size()<n) return {};
        return ans;
    }
};