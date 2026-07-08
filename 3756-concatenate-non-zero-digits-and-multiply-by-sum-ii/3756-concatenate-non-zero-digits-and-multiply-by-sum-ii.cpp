class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_num(m + 1, 0);
        vector<int> non_zero_cnt(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pref_sum[i + 1] = pref_sum[i];
            pref_num[i + 1] = pref_num[i];
            non_zero_cnt[i + 1] = non_zero_cnt[i];

            if (s[i] != '0') {
                int digit = s[i] - '0';
                
                pref_sum[i + 1] = (pref_sum[i + 1] + digit);
                
                pref_num[i + 1] = (pref_num[i + 1] * 10 + digit) % MOD;
                
                non_zero_cnt[i + 1]++;
            }
        }

        vector<int> answer;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

           
            int L = l + 1;
            int R = r + 1;

           
            long long current_sum = pref_sum[R] - pref_sum[L - 1];
            int power = non_zero_cnt[R] - non_zero_cnt[L - 1];
            
            long long current_num = pref_num[R] - (pref_num[L - 1] * power10[power]) % MOD;
            
            current_num = (current_num + MOD) % MOD;

            long long ans = (current_num * (current_sum % MOD)) % MOD;
            answer.push_back(ans);
        }

        return answer;
    }
};