class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto&i:s){
            if(i=='('||i=='{'||i=='[') st.push(i);
            else{
                if(st.empty()) return 0;
                if(i==')'){
                    if(st.top()!='(') return 0;
                }
                if(i=='}'){
                    if(st.top()!='{') return 0;
                }
                if(i==']'){
                    if(st.top()!='[') return 0;
                }
                st.pop();
            }
        }

        return st.empty()==1;
    }
};