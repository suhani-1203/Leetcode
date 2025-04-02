class Solution {
public:
void generateSubsets(int index,vector<int>& nums,vector<int>& subset,vector<vector<int>>& ans){
    ans.push_back(subset);
    for(int i=index;i< nums.size();i++){
        if(i>index && nums[i-1]==nums[i])
            continue;
        subset.push_back(nums[i]);
        generateSubsets(i+1,nums,subset,ans);
        subset.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        generateSubsets(0,nums,subset,ans);
        return ans;
    }
};