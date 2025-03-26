class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> prefixSum;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(prefixSum.count(rem)){
                return{prefixSum[rem],i};
            }
            prefixSum[nums[i]]=i;
        }
        return {};
    }
};