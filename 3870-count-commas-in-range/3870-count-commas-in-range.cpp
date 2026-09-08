class Solution {
public:
    int countCommas(int n) {
        int res=0;
        for(int i=0;i<=n;++i){
            if(i>999){
                res+=1;
            }
        }
        return res;
    }
};