class Solution {
public:
    void recurSubset(vector<vector<int>>& ans ,vector<int>& nums,vector<int>& temp,int index,int n, int k, int sum){
    if(index==n){
        if(sum==k)
            ans.push_back(temp);
        return;
    }
    if(sum>k)
        return;
    if(nums[index]<=k){
        temp.push_back(nums[index]);
        recurSubset(ans,nums,temp,index,n,k-nums[index],sum);
        temp.pop_back();
    }

    recurSubset(ans,nums,temp,index+1,n,k,sum);
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurSubset(ans,candidates,temp,0,candidates.size(),target,0);
        return ans;
    }
};