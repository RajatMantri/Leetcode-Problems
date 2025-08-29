class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,char> p;
        if(s.length()!=t.length()) return false;

        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()&&m[s[i]]!=t[i]) return false;
            if(p.find(t[i])!=p.end()&&p[t[i]]!=s[i]) return false;
            p[t[i]]=s[i];
            m[s[i]]=t[i];
        }

        m.clear();

        // for(int i=0;i<s.length();i++){
        //     if(m.find(t[i])!=m.end()&&m[t[i]]!=s[i]) return false;
        //     m[t[i]]=s[i];
        // }

        return true;
    }
};