int main() {
    // 일단 BFS 돌릴 board[i][j] == 0인 부분을 Queue에 넣고
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            queue <pair<int, int>> Q;
            if (board[i][j] != 0 && vis[i][j] == 0) {
                cnt++;
                Q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    // BFS 구동.
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }
    // 주변 0 개수만큼 감소된 부분 갱신
    ...
    // 분리되었는가? 검사.
    ...

}