class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen=0;
        int segLen=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                segLen++;
                }
            maxLen=max(maxLen,segLen);
            if(nums[i]==0)
                segLen=0;
        }
        return maxLen;

    }
};