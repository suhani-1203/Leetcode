class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxP=0;
        for(int i=0;i<prices.size();i++){
            if(buy>prices[i]){
                buy=prices[i];
            }
                maxP=max(maxP,prices[i]-buy);
        }
        return maxP;
    }
};