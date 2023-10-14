#include<iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
vector<vector<int>> adj = { 99999,vector<int>() };
int vis[10000] = { -1 };
int trace[ 10000] = {-1 };
vector < pair<int, int>> pigval ;
int dep = 0, val = 0;

void dfs(int p, int cur) {
	vis[cur] = dep++;
	trace[cur] = cur;
	//bool ap = false;
	int child = 0;
	for (auto& i : adj[cur]) {
		if (vis[i] != -1) {
			if (i != p)
				if (vis[i] < vis[trace[cur]])
					trace[cur] = i;
			continue;
		}
		else {
			child++;
			dfs(cur, i);

			if (vis[trace[i]] < vis[trace[cur]])
				trace[cur] = trace[i];
			
			
		}
			if (vis[trace[i]] >= vis[cur] &&(child > 1 || p != cur))
				pigval[cur].second++;
			
	}
	
}

int main() {
	int n, m;
	while (cin >> n >> m && n && m) {
		int x, y;
		adj.assign(99999, vector<int>());
		while (cin >> x >> y && x != -1 && y != -1) {
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dep = 0;
		memset(vis, -1, sizeof(vis));
		memset(trace, -1, sizeof(trace));
		pigval.clear();
		for (int i = 0; i < n; ++i) pigval.push_back(pair<int, int>(i, 1));
		for (int i = 0; i < n; i++) {
			if (vis[i] == -1)
				dfs(i, i);
		}
		auto cmp = [](pair<int, int>& l, pair<int, int>& r)
		{
			return l.second != r.second ? l.second > r.second : l.first < r.first;
		};
		sort(pigval.begin(), pigval.end(),cmp);
		for (int i = 0; i < m; i++) {
			cout << pigval[i].first << " " << pigval[i].second << endl;
			
		}
		cout << endl;
	}

	return 0;
}