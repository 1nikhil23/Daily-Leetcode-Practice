class Solution {
int lowerBound(vector<int>& arr,int k,int n){
    int low=0 ,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int>& arr,int n,int k){
    int low=0 ,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]> k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target, nums.size());
        if(lb == nums.size() || nums[lb] != target) return{-1,-1};
        return {lb, upperBound(nums, nums.size(), target) - 1};
    }
};