class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
        long long count=1000;
        while(count<=n){
            res+=n-count+1;
            count*=1000;
        }
        return res;
    }
};