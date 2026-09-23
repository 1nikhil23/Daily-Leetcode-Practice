class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int targ=total-x, l=nums.size(), i=0, cs=0, mx=INT_MIN;
        for(int j=0;j<l;j++){
            cs+=nums[j];
            while(i<=j && cs>targ) cs-=nums[i++];
            if(cs==targ) mx=max(mx,j-i+1);
        }
        return (mx==INT_MIN)?-1:l-mx;
    }
};