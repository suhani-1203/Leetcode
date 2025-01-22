class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen=0;
        int i=0;
        while(i<nums.size()){
            int segLen=0;
            if(nums[i]==1){
                while(i<nums.size() && nums[i]==1){
                    segLen++;
                    i++;
                }
                if(segLen>maxLen)
                    maxLen=segLen;
            }
            i++;
        }
        return maxLen;

    }
};