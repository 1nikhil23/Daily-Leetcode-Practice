class Solution {
public:
    int minSumOfLengths(vector<int>& a, int target) {
        int n = a.size();
        vector<int> best(n, INT_MAX);

        int l = 0, sum = 0, ans = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += a[r];

            while (sum > target)
                sum -= a[l++];

            if (r > 0)
                best[r] = best[r - 1];

            if (sum == target) {
                int len = r - l + 1;

                if (l > 0 && best[l - 1] != INT_MAX)
                    ans = min(ans, len + best[l - 1]);

                best[r] = min(best[r], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};