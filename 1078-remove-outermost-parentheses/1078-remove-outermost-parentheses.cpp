class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string temp="";
        string ans="";
        vector<string> elements;
        for(auto it:s){
            temp+=it;
            if(it=='(')
                count++;
            else{
                count--;
                if(count==0){
                    elements.push_back(temp);
                    temp="";
                 }
            }
        }
        for(auto it: elements){
            for(int i=1;i<it.size()-1;i++)
                ans+=it[i];
        }
    return ans;
    }
};