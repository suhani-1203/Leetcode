class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        stack<int> st;
        int* arr=new int[100000];
        
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i])
                st.pop();

            if(!st.empty())
                arr[nums2[i]]=st.top();
            
            else
                arr[nums2[i]]=-1;

            st.push(nums2[i]);
        
        }
        for(auto it: nums1){
            nge.push_back(arr[it]);
        }
        return nge;
    }
};