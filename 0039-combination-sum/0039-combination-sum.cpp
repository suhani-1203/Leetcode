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
    recurSubset(ans,nums,temp,index+1,n,k,sum);
    temp.push_back(nums[index]);
    sum+=nums[index];
    recurSubset(ans,nums,temp,index,n,k,sum);
    temp.pop_back();
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurSubset(ans,candidates,temp,0,candidates.size(),target,0);
        return ans;
    }
};