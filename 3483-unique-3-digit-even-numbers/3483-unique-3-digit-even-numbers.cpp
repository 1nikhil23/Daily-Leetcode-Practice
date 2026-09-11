class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans=0;
        bool vis[1000]{};
        for(int i=0;i<digits.size();++i){
            if (digits[i] == 0) {
                continue;
            }
            for(int j=0;j<digits.size();++j){
                if (j == i) {
                    continue;
                }
                for(int k=0;k<digits.size();++k){
                    if(k==i||k==j||digits[k]%2!=0){
                        continue;
                    }
                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (!vis[x]) {
                        vis[x] = true;
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};