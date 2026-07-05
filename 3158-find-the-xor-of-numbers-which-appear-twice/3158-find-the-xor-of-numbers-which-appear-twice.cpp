class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans=0;
        long long visited=0;
        for(int num:nums){
            if((visited & (1LL << num)) != 0) {
                ans ^= num;
            }else {
                visited |= (1LL << num);
            }
           
        }
        return ans;
    }
};