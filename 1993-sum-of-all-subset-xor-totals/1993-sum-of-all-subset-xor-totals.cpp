class Solution {
public:
int sum=0;
    void generateSubsets(vector<int>& nums,vector<int>& temp,int index){
        if(index==nums.size()){
            int xor_elements=0;
            for(int x:temp){
                xor_elements^=x;
            }
            sum+=xor_elements;
            return;
        }
        generateSubsets(nums,temp,index+1);
        temp.push_back(nums[index]);
        generateSubsets(nums,temp,index+1);
        temp.pop_back();
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> temp;
        generateSubsets(nums,temp,0);
        return sum;
    }
};