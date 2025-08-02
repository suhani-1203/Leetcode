class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int centre=0;centre<2*n-1;centre++){
            int left=centre/2;
            int right=left+centre%2;

            while(left>=0 && right<n && s[left]==s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};