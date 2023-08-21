class Solution {
   
    const char maskToValue[10] = {'1','2','9','3','5','6','8','4','7','6'};
    struct SudokuSolver {
        array<array<uint16_t,9>,9> board;
        SudokuSolver()
        {
           
            for (int i=0; i<9; i++)
                for (int j=0; j<9; j++)
                    board[i][j] = 0x1ff;
        }
        bool add(int i, int j, int v)
        {
            return set(i, j, 1<<(v-1));
        }
        bool set(int i, int j, uint16_t mask)
        {
            int16_t prev = board[i][j];
            if (prev == mask) return true;
            if (!(prev&mask)) return false;
            board[i][j] = mask;
            return propagate(i,j,mask);
        }
        bool propagate(int i, int j, uint16_t mask)
        {
            for (int k=0; k<9; k++) {
                if (k!=j && !addConstraint(i, k, mask)) return false;
                if (k!=i && !addConstraint(k, j, mask)) return false;
                int ii = (i/3)*3 + (k/3);
                int jj = (j/3)*3 + (k%3);
                if ((i != ii || j != jj) && !addConstraint(ii, jj, mask)) return false;
            }
            return true;
        }
        bool addConstraint(int i, int j, uint16_t mask)
        {
            int16_t newMask = board[i][j] &~ mask;
            if (newMask != board[i][j]) {
                if (newMask == 0) return false;
                board[i][j] = newMask;
                if (((newMask-1)&newMask)==0) {
                    
                    return propagate(i, j, newMask);
                }
            }
            return true;
        }
        vector<pair<int,int>> v;
        void solve()
        {
            for (int i=0; i<9; i++) {
                for (int j=0; j<9; j++) {
                    uint16_t mask = board[i][j];
                    if (mask&(mask-1)) v.push_back(make_pair(i,j));
                }
            }
            
            backtrack(0);
        }  
        bool backtrack(int k) {
            if (k == v.size()) return true;
            int i = v[k].first;
            int j = v[k].second;
            uint16_t mask = board[i][j];
            if (mask&(mask-1)) {
                
                auto snapshot = board;
                for (uint16_t cand = 1; cand<=0x1ff; cand = cand <<1) {
                    if (set(i, j, cand) && backtrack(k+1)) return true;
                    board = snapshot;
                }
                return false;
            }
            else {
                return backtrack(k + 1);
            }
        }
        
    };
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        SudokuSolver solver;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char c = board[i][j];
                if (c != '.' && !solver.add(i,j,c-'0')) return;
            }
        }
       
        solver.solve();
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                board[i][j] = maskToValue[(solver.board[i][j]%11)-1];
    }
};