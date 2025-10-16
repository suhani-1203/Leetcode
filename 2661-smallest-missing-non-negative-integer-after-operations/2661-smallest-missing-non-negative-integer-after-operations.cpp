class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>freq(value);
        for(int &i:nums){
            int r=((i%value)+value)%value;
            freq[r]++;
        }
        int mex=0;
        while(true){
            int r=mex%value;
            if(freq[r]>0){
                freq[r]--;
                mex++;
            }
            else{
                break;
            }
        }
        return mex;
    }
};