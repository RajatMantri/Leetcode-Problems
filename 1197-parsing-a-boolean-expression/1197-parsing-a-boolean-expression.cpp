class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == ',') continue; // commas are useless
            
            if (c != ')') {
                // push everything except ')'
                st.push(c);
            } else {
                // we found a ')', so evaluate subexpression
                vector<char> vals;
                while (!st.empty() && st.top() != '(') {
                    vals.push_back(st.top());
                    st.pop();
                }

                st.pop(); // remove '('
                char op = st.top(); // operator before '('
                st.pop();

                bool ans;
                if (op == '!') {
                    ans = (vals.back() == 'f'); // only one value
                } else if (op == '&') {
                    ans = true;
                    for (char v : vals) ans &= (v == 't');
                } else { // op == '|'
                    ans = false;
                    for (char v : vals) ans |= (v == 't');
                }

                st.push(ans ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};
