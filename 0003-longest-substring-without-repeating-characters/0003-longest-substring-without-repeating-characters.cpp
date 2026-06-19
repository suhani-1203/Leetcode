class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        if(len==0) return 0;

        int hash[256];
        memset(hash,-1,sizeof(hash));

        int left=0,right=0,ans=0;

        while(left<=right && right<len){
            left=max(left,hash[s[right]]+1);
            hash[s[right]]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};