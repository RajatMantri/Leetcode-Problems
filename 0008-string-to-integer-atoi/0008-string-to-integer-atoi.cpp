class Solution {
public:
    int myAtoi(string s) {
        bool neg=0;
        long long ans=0,n=s.length(),i=0;

        while(i<n&&s[i]==' ') i++;
        
        if(i<n&&(s[i]=='+'||s[i]=='-')){
            if(s[i]=='-') neg=1;
            i++;
            //to check if next character after +/- is in range(0,9)
            if(i<n&&(s[i]-'0'<0||s[i]-'0'>9)) return ans;
        }

        int start=i;
        int end=i;
        
        while(s[start]-'0'==0) start++;
        while(i<n&&s[i]-'0'>=0&&s[i]-'0'<=9) i++;
        end=i-1;

        //INT_MAX 2147483647 Length=10 at most difference b/w end and start can be 9 
        if(end-start>9&&neg) return INT_MIN;
        if(end-start>9&&!neg) return INT_MAX;

        int p=0;
        while(start<=end){
            int num=s[end--]-'0';
            ans+=num*pow(10,p++);
            //if(ans>INT_MAX) break;
        }

        if(neg) ans*=-1;
        if(ans>INT_MAX) ans=INT_MAX;
        if(ans<INT_MIN) ans=INT_MIN;

        return ans;
    }
};