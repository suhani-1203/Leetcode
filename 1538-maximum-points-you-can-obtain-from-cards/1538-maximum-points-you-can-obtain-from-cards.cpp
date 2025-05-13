class Solution {
public:
        int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,maxScore=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        maxScore=lsum;
        int rsum=0,rindex=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rindex];
            rindex--;
            maxScore=max(maxScore,lsum+rsum);
        }
        return maxScore;
    }
};