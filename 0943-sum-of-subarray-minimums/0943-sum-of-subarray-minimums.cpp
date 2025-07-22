class Solution {
public:
    const int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        //creating nse vector for each element
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        // creating pse vector for each element
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(!st.empty())
                pse[i]=st.top();
            st.push(i);
        }
        // finding contribution of each element in minimums
        int sum=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            sum=(sum+1LL*left*right%mod*arr[i]%mod)%mod;
        }
        return sum;
    }
};