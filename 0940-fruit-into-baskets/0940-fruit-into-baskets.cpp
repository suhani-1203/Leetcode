class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mpp;
        int left=0,right=0,maxLen=0;

        while(right<n){
            mpp[fruits[right]]++;

            if(mpp.size()>2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]]==0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            if(mpp.size()<=2)
                maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};