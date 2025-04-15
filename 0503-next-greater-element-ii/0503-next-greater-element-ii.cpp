class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        int* arr=new int[2*n];
        for(int i=0;i<2*n-1;i++)
            arr[i]=nums[i%n];
        arr[2*n-1]=nums[n-1];
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(i<n && !st.empty())
                nge[i]=st.top();
        
            st.push(arr[i]);
        }
        delete[] arr;
        return nge;
    }
};