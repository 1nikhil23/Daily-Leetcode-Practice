class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char ,int>f;
        int left=0;
        int ans=0;
        for(int right=0;right<s.size();right++){
            f[s[right]]++;
            while(f['a']>0 && f['b']>0 && f['c']>0){
                 ans += s.size()-right;
                 f[s[left]]--;
                 left++;;
            }
        }
        return ans;
    }
};