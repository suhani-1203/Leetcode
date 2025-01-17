class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(i<n && j<n){
            if(nums[i]==nums[j])
                j++;
            else{
                i++;
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j++;
            }
        }
        return i+1;

    }
};