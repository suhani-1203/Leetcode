class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int left=0,right=n-1;
        vector<int> indices;
        while(left<=right){
            int sum=numbers[left]+numbers[right];
            if(sum==target){
                indices.push_back(left+1);
                indices.push_back(right+1);
                break;
            }
            else if(sum<target)
                left++;
            else
                right--;
        }
        return indices;
    }
};