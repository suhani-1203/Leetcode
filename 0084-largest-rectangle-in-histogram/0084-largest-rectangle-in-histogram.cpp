class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==1)
            return heights[0];
        vector<int> pse(n,-1);
        vector<int> nse(n,n);

         stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                nse[i]=st.top();
            st.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            maxArea=max(maxArea,width*heights[i]);
        }
        return maxArea;
    }
};