#include<bits/stdc++.h>
using namespace std;

int main() {
    int R, C, T;
    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    pair<int, int> firstExplosive;
    int totalExplosives = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'E' || grid[i][j] == 'F') {
                totalExplosives++;
                if(grid[i][j] == 'F') {
                    firstExplosive = {i, j};
                }
            }
        }
    }
    cin >> T;
    queue<pair<int, int>> q;
    q.push(firstExplosive);
    visited[firstExplosive.first][firstExplosive.second] = true;
    int time = 0, exploded = 0;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while(!q.empty()) {
        int size = q.size();
        exploded += size;
        for(int i = 0; i < size; i++) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int j = 0; j < 8; j++) {
                int nx = cur.first + dx[j], ny = cur.second + dy[j];
                if(nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && (grid[nx][ny] == 'E' || grid[nx][ny] == 'F')) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        if(!q.empty()) time += T;
    }
    cout << totalExplosives - exploded << " " << time << endl;
    return 0;
}
