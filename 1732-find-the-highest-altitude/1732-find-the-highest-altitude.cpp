class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int maxAlt=0,alt=0;
        for(int i=0;i<n;i++){
            alt=alt+gain[i];
            maxAlt=max(alt,maxAlt);
        }
        return maxAlt;
    }
};