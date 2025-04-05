class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word,int i,int j,int k){
        if(k==word.length()){
            return true;
        }
        if(i>=board.size() || i<0 || j<0 || j>=board[0].size() ||board[i][j]!=word[k])
            return false;
        
        char temp=board[i][j];
        board[i][j]='\0';
        if(backtrack(board,word,i+1,j,k+1)||backtrack(board,word,i,j+1,k+1)||backtrack(board,word,i,j-1,k+1)||backtrack(board,word,i-1,j,k+1))
            return true;

        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<(board[0].size());j++){
                if(backtrack(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};