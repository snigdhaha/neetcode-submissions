class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row;    
        unordered_set<char> col;
        unordered_set<char> box;
        unordered_set<string> seen;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num = board[i][j];

                if(num == '.') continue;
                //5row0 -> 5 is in row 0
                string row = string(1, num) + "row" + to_string(i);
                string col = string(1, num) + "col" + to_string(j);
                int box = (i / 3) * 3 + (j / 3);
                string boxStr = string(1, num) + "box" + to_string(box);

                if(seen.count(row) || seen.count(col) || seen.count(boxStr))
                    return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(boxStr);


            }
        }
        return true;
    }
};
