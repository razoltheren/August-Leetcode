class Solution {
    void dfs(int num, int N, int K, vector<int>& result){
        if(N == 0){
            result.push_back(num);
            return;
        }
        int last_digit = num%10;
        if(last_digit >= K) dfs(num*10 + last_digit - K, N-1, K, result);
        if(K > 0 && last_digit + K < 10) dfs(num*10 + last_digit + K, N-1, K, result);
    }
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        if(N == 1) result.push_back(0);
        for(int d = 1; d < 10; ++d)
            dfs(d, N-1, K, result);
        
        return result;
    }
};

