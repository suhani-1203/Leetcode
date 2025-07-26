class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> numsIndex;
        vector<int> indices;
        for(int i=0;i<n;i++){
            int complement=target-nums[i];
            if(numsIndex.count(complement)){
                indices.push_back(numsIndex[complement]);
                indices.push_back(i);
                break;
            }
            numsIndex[nums[i]]=i;
        }
        return indices;
    }
};