class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum=0,count=0;
        for(auto num:nums){
            sum+=num;
            if(mpp.count(sum-k)){
                count+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return count;
    }
};