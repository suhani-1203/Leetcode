class Solution {
public:
    void recurSubset(vector<vector<int>>& ans ,vector<int>& nums,vector<int>& temp,int index,int n, int k){
    if(k==0){
        ans.push_back(temp);
        return;
    }
    if(index==n)
        return;
    for(int i=index;i<n;i++){
        if(nums[i]>k)
            continue;
        temp.push_back(nums[i]);
        recurSubset(ans,nums,temp,i,n,k-nums[i]);
        temp.pop_back();
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurSubset(ans,candidates,temp,0,candidates.size(),target);
        return ans;
    }
};