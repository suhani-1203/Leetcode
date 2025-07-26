class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int res=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int k=nums[i];
            int left=i+1,right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(abs(target-sum)< abs(target -res))
                    res=sum;
                else if(sum<target)
                    ++left;
                else
                    --right;
            }
        }
        return res;
    }
};