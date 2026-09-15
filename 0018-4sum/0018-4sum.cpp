class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        int n = a.size();

        for (int i = 0; i < n - 3; i++) {
            if (i && a[i] == a[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && a[j] == a[j - 1]) continue;
                int k = j + 1, l = n - 1;

                while (k < l) {
                    long long sum = 1LL * a[i] + a[j] + a[k] + a[l];

                    if (sum == target) {
                        ans.push_back({a[i], a[j], a[k], a[l]});

                        while (k < l && a[k] == a[k + 1]) k++;
                        while (k < l && a[l] == a[l - 1]) l--;

                        k++; l--;
                    }
                    else if (sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};