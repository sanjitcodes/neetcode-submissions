class Solution {
public:
    void dfs(vector<vector<char> >&board, vector<vector<bool>>&vis, int n, int m, int i, int j){
        if(i < 0 || j < 0 || i>=n || j >= m || vis[i][j] || board[i][j] == 'X') return;
        vis[i][j] = 1;
        dfs(board, vis, n, m, i+1, j);
        dfs(board, vis, n, m, i-1, j);
        dfs(board, vis, n, m, i, j+1);
        dfs(board, vis, n, m, i, j-1);    
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool> > vis(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(board, vis, n, m, i, 0);
            }
            if(board[i][m-1] == 'O'){
                dfs(board, vis, n, m, i, m-1);
            }
        }
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                dfs(board, vis, n, m, 0, j);
            }
            if(board[n-1][j] == 'O'){
                dfs(board, vis, n, m, n-1, j);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }


    }
};
