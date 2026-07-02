class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long sum=0;
        int left=0;
        int ans=1;
        sort(nums.begin(),nums.end());
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while((long long)(right-left+1)*nums[right]-sum >k){
              sum-=nums[left];
                left++;
            }
            ans=max(ans ,right-left+1);
        }
        return ans;
    }
};