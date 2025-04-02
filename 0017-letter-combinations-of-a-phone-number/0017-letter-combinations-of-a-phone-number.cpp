class Solution {
public:
    void solveDigit(string& digit,string& output,int i,vector<string>& ans,string (&mapping)[10]){
        if(i>=digit.length()){
            ans.push_back(output);
            return;
        }
        int num=digit[i]-'0';
        string value=mapping[num];

        for(int j=0;j<value.length();j++){
            output.push_back(value[j]);
            solveDigit(digit,output,i+1,ans,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digit) {
    vector<string> ans;
    if(digit.length()==0)
        return ans;
        string output;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solveDigit(digit,output,0,ans,mapping);
    return ans;

   }
};