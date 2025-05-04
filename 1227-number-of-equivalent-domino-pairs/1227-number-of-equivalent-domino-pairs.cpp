class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
    int res = 0;
    
    for (auto& d : dominoes) {
        
        int a = min(d[0], d[1]);
        int b = max(d[0], d[1]);
        int key = a * 10 + b;  

        res += count[key]; 
        count[key]++;
    }
    
    return res;
    }
};