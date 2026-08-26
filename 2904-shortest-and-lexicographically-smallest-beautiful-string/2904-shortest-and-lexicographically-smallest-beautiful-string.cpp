class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int count = 0;

        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1') {
                count++;
            }
            if (count == k) {
                while (s[left] == '0') {
                    left++;
                }
                string curr = s.substr(left, right - left + 1);
                if (ans == "" ||
                    curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }
                left++;
                count--;
            }
        }
        return ans;
    }
};