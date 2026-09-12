class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        static const auto fast_io = []() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            return nullptr;
        }();

        int col[9] = {0};
        int row[9] = {0};
        int box[9] = {0};
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                int encoded = 1 << val;
                int boxIdx = (i / 3) * 3 + j / 3;

                if (col[j] & encoded || row[i] & encoded ||
                    box[boxIdx] & encoded) {
                        return false;
                }

                col[j] |= encoded;
                row[i] |= encoded;
                box[boxIdx] |= encoded;
            }
        }
        
        return true;
    }
};
