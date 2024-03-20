#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int groupCount = 0;
int R, C;

void dfs(int row, int col) {
    if (row >= 0 && row < R && col >= 0 && col < C && !visited[row][col]) {
        visited[row][col] = true;
        if (grid[row][col] == 1) {
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int new_row = row + dr;
                    int new_col = col + dc;
                    dfs(new_row, new_col);
                }
            }
        }
    }
}

int main() {
    cin >> R >> C;
    grid.resize(R, vector<int>(C));
    visited.resize(R, vector<bool>(C, false));

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
        }
    }

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (!visited[row][col] && grid[row][col] == 1) {
                groupCount++;
                dfs(row, col);
            }
        }
    }

    cout << groupCount << endl;
    return 0;
}