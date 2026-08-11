class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int left=0;
        int ans=nums[0];
        for(int right=1;right<nums.size();right++){
            if(nums[right]==nums[right-1]+1){
                ans +=nums[right];
            }else{
                break;
            }
           
        }
        while(num_set.count(ans)){
            ans +=1;
        }
        return ans;

    }
};