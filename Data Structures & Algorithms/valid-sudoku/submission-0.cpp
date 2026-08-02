class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current_val = board[i][j];
                if (current_val == '.') {
                    continue;
                }
                string row_str = string(1, current_val) + " found in row " + to_string(i);
                string col_str = string(1, current_val) + " found in col " + to_string(j);
                string box_str = string(1, current_val) + " found in box " + to_string(i / 3) + "-" + to_string(j / 3);
                if (!seen.insert(row_str).second || !seen.insert(col_str).second || !seen.insert(box_str).second) {
                    return false;
                }
            }
        }
        return true;
    }
};
