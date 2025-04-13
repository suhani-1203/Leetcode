class Solution {
public:    
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int maxLen=0;
        int hash[256];
        memset(hash,-1,sizeof(hash));
            while(left<=right && right<s.length()){
                if(hash[s[right]]!=-1){
                    if(hash[s[right]]>=left)    left=hash[s[right]]+1;
                }
                hash[s[right]]=right;
                maxLen=max(maxLen,(right-left+1));
                right++;
            }
        return maxLen;
    }
};