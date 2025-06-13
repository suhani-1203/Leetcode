class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        
        for(int it: nums)
            pq.push(it);
        for(int i=1;i<k;i++)
            pq.pop();

        return pq.top();
    }
};