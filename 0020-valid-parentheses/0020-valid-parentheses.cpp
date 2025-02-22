class Solution {
public:
    bool isValid(string s) {
        if(s.length()==1)
            return false;

        stack<char> st;
        
        for(auto it :s){
            if(it=='(' || it=='{'||it=='[')
                st.push(it);
                if(st.empty())
                    return false;
            else{
                if(it==')'){
                    if(st.top()=='('){
                        st.pop();
                        continue;
                    }
                    else 
                        return false;
                }
                else if(it=='}'){
                    if(st.top()=='{'){
                        st.pop();
                        continue;
                    }
                    else
                        return false;
                }
                else if(it==']'){
                    if(st.top()=='['){
                        st.pop();
                        continue;
                    }
                    else
                        return false;
                }

            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};