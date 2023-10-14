#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int casenum, n,alive = 0;
int dir[4][2] = { {1,0},{-1,0},{-1,0},{0,1} };
string grid[100] = { "" };
int vis[100][100] = { 0 };

void bfs(pair<int,int> now) {
	queue < pair<int, int>> q;
	q.push(now);
	vis[now.second][now.first] = 1;
	if (grid[now.second][now.first] == 'x')	alive = 1;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { now.first + dir[i][0],now.second + dir[i][1] };
			if (next.second < 0 || next.second >= n || next.first < 0 || next.first >= n || vis[next.second][next.first] == 1 || grid[next.second][next.first] == '.')	continue;
			vis[next.second][next.first] = 1;
			if (grid[next.second][next.first] == 'x')	alive = 1;
			q.push(next);
		}
	}
}

int main() {
	cin >> casenum;
	int casen = 0;
	while (++casen && casen <= casenum) {
		cin >> n;
		getchar();
		
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			string t;
			getline(cin, grid[i]);
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] == 0 && grid[i][j] !='.') {
					alive = 0;
					bfs({ j,i });
					if (alive == 1)
						sum++;
				}
					
			}
		}
		cout <<"Case "<<casen<<": " << sum << endl;
	}
	return 0;
}