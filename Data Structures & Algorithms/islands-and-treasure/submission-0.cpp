class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int> > q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        vector<int> dx {-1, 0, 1, 0};
        vector<int> dy {0, -1, 0, 1};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0||nx>=n||ny<0||ny>=m)
                    continue;

                if(grid[nx][ny]!=INT_MAX)
                    continue;

                grid[nx][ny]=grid[x][y]+1;

                q.push({nx,ny});
            }
        }

    }
};
