class Solution {
public:
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board, i, j, word)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int m, int n, string& word){
        
        // 檢查都對 return true
        if(word.size() == 0) return true;
        
        // 出界
        if(m < 0 || n < 0 || m >= board.size() || n >= board[0].size()) return false;
        
        if(board[m][n] != word[0]) return false;
        
        // save temp character and remove
        char c = board[m][n];
        board[m][n] = '.';
        
        // check 
        string s = word.substr(1);
        
        
       
        bool ret =  dfs(board, (m-1), (n), s) || 
                    dfs(board, (m), (n-1), s) || 
                    dfs(board, (m+1), (n), s) || 
                    dfs(board, (m), (n+1), s);
            
        board[m][n] = c;
        return ret;
    }
};