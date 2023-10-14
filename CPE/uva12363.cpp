#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int>> corrider = { 10001,vector<int>() };
int vis[10001] = { 0 };
int trace[10001] = { 0 };
vector<pair<int, int>> birdge;
int dep = 0;

void dfs(int p, int cur) {
	
	vis[cur] = dep++;
	trace[cur] = cur;

	for (auto& i : corrider[cur]) {
		if (vis[i]) {
			if (i != p)
				if (vis[i] < vis[trace[cur]])
					trace[cur] = i;
		}
		else {
			dfs(cur, i);

			// 記錄第i點的子孫們用back edge連到的最高祖先
			if (vis[trace[i]] < vis[trace[cur]])
				trace[cur] = trace[i];

			// 子樹回不到祖先暨自身。
			if (vis[trace[i]] > vis[cur])
				birdge.push_back({cur, i});
		}
	}
}

int group[10000] = { -1 };
int find_root(int x) {
	if (x == group[x])	return x;

	int root = find_root(group[x]);
	group[x] = root;
	return root;
}

void join(int x,int y) {
	int x_root = find_root(x);
	int y_root = find_root(y);
	group[x_root] = y_root;
}

int main() {
	int r, c, q;
	while (cin >> r >> c >> q &&( r || c || q)) {
		corrider.assign(r + 1, vector<int>());
		
		for (int i = 0; i < c; i++){
			int a, b;
			cin >> a >> b;
			corrider[a].push_back(b);
			corrider[b].push_back(a);
		}
		memset(vis, 0, sizeof(vis));
		memset(trace, 0, sizeof(trace));
		birdge.clear();
		dep = 0;
		for (int i = 1; i <= r; i++) {
			if (vis[i] == 0)
				dfs(i,i);
		}
		
		for (int i = 1; i <= r; i++)
			group[i] = i;

		for (auto& i : birdge) {
			join(i.first, i.second);
		}
			
		
		int beg, end;
		for (int i = 1; i <= q; i++) {
			cin >> beg >> end;
			if (find_root(beg) == find_root(end))
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		}
		

		cout << "-"<<endl;
	}
	return 0;
}

