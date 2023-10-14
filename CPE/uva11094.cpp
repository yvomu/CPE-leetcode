#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, x, y;
string map[25] = {""};
int vis[25][25] = { 0 };
char land;
int dir[4][2] = { {1,0}, {0,1},{-1,0},{0,-1} };
int landsum = 0;

void bfs(int y, int x, char reigon) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[y][x] = 1;
	landsum++;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx == n)	nx = 0;
			if (nx == -1)	nx = n-1;
			if (ny < 0 ||  ny >= m || map[ny][nx] != reigon||vis[ny][nx]) 	continue;
			vis[ny][nx] = 1;
			landsum++;
			q.push({ nx,ny });
		}
	}
}

int main() {
	while (cin >> m >> n) {
		getchar();
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++) {
			getline(cin, map[i]);
		}
		cin >> y >> x;
		land = map[y][x];
		bfs( y,x , land);
		int max = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != land || vis[i][j])	continue;
				landsum = 0;
				bfs(i, j, land);
				if (max < landsum)
					max = landsum;
			}
		}
		cout << max << endl;
	}
	return 0;
}