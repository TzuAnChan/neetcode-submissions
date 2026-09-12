class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        static const auto fast_io = []() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            return nullptr;
        }();
        int col[9] = {0}, row[9] = {0}, box[9] = {0};

        for (int i = 0; i < 9; ++i) {
            int bRow = (i / 3) * 3; // 把除法提出來，少算 9 次除法
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                int mask = 1 << (c - '1');
                int bIdx = bRow + (j / 3);

                if ((row[i] | col[j] | box[bIdx]) & mask) return false;

                row[i] |= mask;
                col[j] |= mask;
                box[bIdx] |= mask;
            }
        }
        return true;
    }
};