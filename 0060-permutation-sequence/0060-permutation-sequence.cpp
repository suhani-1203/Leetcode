class Solution {
public:
    int factorial(int n){
        int fact=1;
        for(int i=2;i<=n;i++){
            fact*=i;
        }
        return fact;
    }
    void getPermutations(int n, int k, string& ans,vector<int>& numbers){
        if(numbers.size()==0)
            return;
        int fact=factorial(n-1);
        ans=ans+to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        k=k%fact;
        n--;
        getPermutations(n,k,ans,numbers);
    }
    string getPermutation(int n, int k) {
        string ans="";
        k=k-1;//0-based indexing
        vector<int> numbers;
        for(int i=1;i<=n;i++)
            numbers.push_back(i);
        getPermutations(n,k,ans,numbers);
        return ans;
    }
};
        