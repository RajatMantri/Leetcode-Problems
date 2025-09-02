class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> operand;//(t,f,'(')
        stack<char> operat;

        for(auto&i:s){
            if(i==')'){
                char ch=operat.top();
                operat.pop();
                
                bool ans=1;
                if(operand.top()=='f') ans=0;
                
                operand.pop();
                
                if(ch=='|'){
                    while(operand.top()!='('){
                        if(operand.top()=='f') ans=ans|0;
                        else if(operand.top()=='t')ans=ans|1;
                        operand.pop();
                    }
                }
                else if(ch=='&'){
                    while(operand.top()!='('){
                        if(operand.top()=='f') ans=ans&0;
                        else if(operand.top()=='t')ans=ans&1;
                        operand.pop();
                    }
                }
                else ans=!ans;
                
                operand.pop();
                
                if(ans) operand.push('t');
                else operand.push('f');
            }
            else if(i=='!'||i=='&'||i=='|') operat.push(i);
            else operand.push(i);
        }

        return operand.top()=='t';
    }
};