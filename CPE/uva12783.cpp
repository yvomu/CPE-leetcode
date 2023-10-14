#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> adj = {10000,vector<int>()};
int vis[1000] = { -1 };
int trace[1000] = { -1 };
vector<pair<int, int>> bridge;
int dep = 0;

void dfs(int p, int cur) {
	vis[cur] = dep++;
	trace[cur] = cur;

	for (auto& i : adj[cur]) {
		if (vis[i] != -1) {
			if (i != p)
				if (vis[i] < vis[trace[cur]])
					trace[cur] = i;
		}
		else {
			dfs(cur, i);

			if (vis[trace[i]] < vis[trace[cur]])
				trace[cur] = trace[i];

			if (vis[trace[i]] > vis[cur])
				bridge.push_back({ min(i,cur) ,max(i,cur) });
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m &&( n || m)) {
		adj.assign(10000, vector<int>());
		memset(vis, -1, sizeof(vis));
		memset(trace, -1, sizeof(trace));
		bridge.clear();
		dep = 0;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 0; i < n; i++) {
			if (vis[i] == -1) {
				dfs(i, i);
			}
		}
		sort(bridge.begin(), bridge.end());

		int size = bridge.size();
		cout << size;
		for (int i = 0; i < size; i++) {
			cout <<" " << bridge[i].first<<" " << bridge[i].second;
		}
		cout << endl;
	}
	return 0;
}