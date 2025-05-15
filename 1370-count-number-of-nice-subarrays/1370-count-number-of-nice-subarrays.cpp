class Solution {
public:
int countArray(vector<int>& nums,int goal){
        if(goal<0)
            return 0;
        int left=0,right=0,sum=0,count=0;
        while(right<nums.size()){
            sum+=(nums[right]%2);
            while(sum>goal){
                sum-=(nums[left]%2);
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int first=countArray(nums,k);
        int second=countArray(nums,k-1);

        return first-second;
    }
};