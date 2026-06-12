class Solution {
public:
    bool isSafe(int &i, int &j, int &n,int &m){
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    bool find(vector<vector<char>>& board,string word,int r,int c,int ch){
        if(board[r][c] != word[ch]) return false;
        if(ch==word.size()-1){
            return true;
        }


        int n=board.size();
        int m=board[0].size();

        char temp = board[r][c];
        board[r][c] = '#';

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        for (int ind = 0; ind < 4; ind++){
            int newRow = r + delRow[ind];
            int newCol = c + delCol[ind];

            if (isSafe(newRow, newCol, n,m)){
                if(find(board,word,newRow,newCol,ch+1)) return true;
            }
        }
        board[r][c] = temp;
    
        return false;

    }
    

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                    
                if(find(board,word,i,j,0)) return true;
                    
                
            }
        }

        return false;

    }
};
