class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int> > row(9, vector<int>(9, 0));
        vector<vector<int> > col(9, vector<int>(9, 0));
        vector<vector<int> > box(9, vector<int>(9, 0));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int cur = board[i][j] - '0' - 1;
                    int k = (i/3)*3 + (j/3);
                    if(row[i][cur] || col[j][cur] || box[k][cur]){
                        return 0;
                    }
                    row[i][cur] = 1;
                    col[j][cur] = 1;
                    box[k][cur] = 1;
                }
            }
        }
        return 1;
    }
};
