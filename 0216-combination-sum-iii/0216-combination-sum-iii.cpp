class Solution {
public:
void generateCombinations(int index,vector<int>& arr,int k,int n,vector<int>& subset,vector<vector<int>>& ans){
    if(subset.size()==k && n==0){
        ans.push_back(subset);
        return;
    }
    if(subset.size()>k || n<0)
        return;
    for(int i=index;i<arr.size();i++){
        if(arr[i] > n ) break;
        subset.push_back(arr[i]);
        generateCombinations(i+1,arr,k,n-arr[i],subset,ans);
        subset.pop_back();
    }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        for(int i=1;i<10;i++)
            arr.push_back(i);
        vector<int> subset;
        vector<vector<int>> ans;
        generateCombinations(0,arr,k,n,subset,ans);

        return ans;
    }
};