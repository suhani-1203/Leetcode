class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        unordered_map<char,int> lastSeen={{'a',-1},{'b',-1},{'c',-1}};
        for(int i=0;i<s.length();i++){
            lastSeen[s[i]]=i;
            if(lastSeen['a']!=-1 && lastSeen['b']!=-1 && lastSeen['c']!=-1)
                count=count+1+min(lastSeen['a'],min(lastSeen['b'],lastSeen['c']));
        }
        return count;
    }
};