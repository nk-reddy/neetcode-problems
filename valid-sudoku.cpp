class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>bSeen(board.size(), unordered_set<char>{});
        for (size_t i = 0; i < board.size(); ++i) {
            unordered_set<char> rSeen;
            unordered_set<char> cSeen;
            for (size_t j = 0; j < board.size(); ++j) {
                if (rSeen.contains(board[i][j])) {
                    return false;
                } 
                if (board[i][j] != '.') {
                    rSeen.insert(board[i][j]);
                    int bIndex = (i / 3) * 3 + (j / 3);
                    if (bSeen[bIndex].contains(board[i][j])) {
                        return false;
                    }
                    bSeen[bIndex].insert(board[i][j]);
                }

                if (cSeen.contains(board[j][i])) {
                    return false;
                }
                if (board[j][i] != '.') {
                    cSeen.insert(board[j][i]);
                }
            }
        }
        return true;
    }
};
