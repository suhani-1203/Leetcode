class Solution {
public:
    void makePermutations(vector<vector<int>>& ans,vector<int>& nums,int n,int index){
        if(index==n){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            makePermutations(ans,nums,n,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        makePermutations(ans,nums,n,0);
        return ans;
    }
};