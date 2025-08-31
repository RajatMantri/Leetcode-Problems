class Solution
{
public:
    vector<int> div;       
    vector<int> ans;    
    int min_diff = 1e9;      

    void solve(int n, int k, vector<int> &temp, int start)
    {
        if(temp.size() == k)
        {
            if(n == 1)
            {
                int cur_diff = temp[k-1] - temp[0];
                if(cur_diff < min_diff)
                {
                    min_diff = cur_diff;
                    ans = temp;
                }
            }
            return;
        }

        for(int i = start; i < div.size(); i++)
        {
            if(div[i] > n) break;       
            if(n % div[i] == 0)         
            {
                temp.push_back(div[i]); 
                solve(n / div[i], k, temp, i);
                temp.pop_back();          
            }
        }
    }

    vector<int> get_divisors(int n)
    {
        vector<int> res;
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                res.push_back(i);
                if(i != n / i) res.push_back(n / i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    vector<int> minDifference(int n, int k)
    {
        div = get_divisors(n);       
        vector<int> temp;
        solve(n, k, temp, 0);           
        return ans;                      
    }
};