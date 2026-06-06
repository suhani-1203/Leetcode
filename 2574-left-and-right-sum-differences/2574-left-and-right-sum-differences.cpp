class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        
    
        for (int num : nums) {
            rightSum += num;
        }

        vector<int> answer(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];              
            answer[i] = abs(leftSum - rightSum); 
            leftSum += nums[i];                
        }
        
        return answer;
    }
};

