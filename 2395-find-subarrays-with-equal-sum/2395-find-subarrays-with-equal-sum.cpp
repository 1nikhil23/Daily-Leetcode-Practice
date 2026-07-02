class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>f;
        for(int i=0;i<nums.size()-1;i++){
            int sum=nums[i]+nums[i+1];
                if(f.find(sum) != f.end()){
                    return true;
                }
            f.insert(sum);
        }
        return false;
    }
};