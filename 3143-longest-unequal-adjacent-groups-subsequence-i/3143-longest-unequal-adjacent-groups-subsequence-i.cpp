class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> dp;
        dp.push_back(words[0]);
        for(int i=1;i<groups.size();i++){
            if(groups[i]==groups[i-1])
                continue;
            else
                dp.push_back(words[i]);
        }
        return dp;
    }
};