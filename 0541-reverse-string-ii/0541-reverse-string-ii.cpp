class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2*k) {
            int start=i, end=min(i + k - 1, (int)s.size() - 1);
            while(start<end){
                swap(s[start++],s[end--]);
            }
        }
        return s;
    }
};