#include<iostream>
#include <queue>
#include <vector>

using namespace std;

//vector<vector<int>> map = { 1005,vector<int>(1005) };
int map[1005][1005] = { 0 };
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
pair<int,int> s,d;
int cnt = -1;
int r, c;
int bfs(pair<int,int> s) {
	queue<pair<int, int>> q;
	q.push(s);
	map[s.first][s.second] = 1;
	while (!q.empty()) {
		int siz = q.size();
		cnt++;
		while (siz--)
		{
			pair<int, int> cur = q.front();
			q.pop();
			
			for (int i = 0; i < 4; i++) {
				pair<int, int> n = { cur.first + dir[i][0],cur.second + dir[i][1] };
				if(n == d)	return ++cnt;
				if (n.second<0 || n.second >= c|| n.first < 0 || n.first >= r|| map[n.first][n.second])	continue;
				q.push(n);
				map[n.first][n.second] = 1;
			}
		}

	}
	
}

int main() {
	
	while (cin >> r >> c && r && c) {
		cnt = -1;
		for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)	map[i][j] = 0;
		int rows;
		cin >> rows;
		while (rows--) {
			int a,b;
			cin >> a >> b;
			while (b--) {
				int c;
				cin >> c;
				map[a][c] = 1;
			}

		}

		cin >> s.first >> s.second >> d.first >> d.second;
		cout <<bfs(s)<<endl;
	}
	return 0;
}