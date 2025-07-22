class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0,right=k-1;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double val=sum;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i]-nums[i-k];
            if(sum>val)
                val=sum;
        }
        return val/double(k);
    }
};