const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(int i=0;i<tasks.size();i++) freq[tasks[i]-'A']++;

        priority_queue<int> q;
        for(int i=0;i<26;i++) if(freq[i]>0) q.push(freq[i]);

        int ans=0;

        while(!q.empty()){
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(!q.empty()){
                    int freq=q.top();q.pop();
                    freq--;
                    temp.push_back(freq);
                }
                else break;
            }

            for(auto& i:temp) if(i>0) q.push(i);

            if(q.empty()) ans+=temp.size();
            else ans+=n+1;
        }

        return ans; 
    }
};