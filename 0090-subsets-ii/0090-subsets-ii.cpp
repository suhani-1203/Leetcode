class Solution {
public:
void generateSubsets(int index,vector<int>& nums,vector<int>& subset,vector<vector<int>>& ans){
    ans.push_back(subset);
    if(index==nums.size())
        return;
    for(int i=index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1])
            continue;
        subset.push_back(nums[i]);
        generateSubsets(i+1,nums,subset,ans);
        subset.pop_back();
    }
    return;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        generateSubsets(0,nums,subset,ans);
        return ans;
    }
};