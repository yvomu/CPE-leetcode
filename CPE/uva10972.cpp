#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
vector<vector<int>> adj = {90000,vector<int>()};
int vis[2000] = { 0 };
int low[2000] = { 0 };
vector<pair<int, int>> bridge;
map<int, int> brightcnt;
int dep,bs;

void dfs(int p, int cur) {
	vis[cur] = low[cur] = ++dep;

	for (auto& i : adj[cur]) {
		if (!vis[i]) 
			dfs(cur, i);
			
		
		if (i != p)
			low[cur] = min(low[cur], low[i]);

		if (low[i] > low[cur]) {
			bridge.push_back({ cur,i });
			
		}
			
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		adj.assign(90000, vector<int>());
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		bridge.clear();
		brightcnt.clear();
		dep = 0;
		int con0 = 0, con1 = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				int tbs = bridge.size();
				dfs(i, i);
				if (bridge.size() == tbs)	con0++;
			}
			
		}
		if (con0 == 1 && bridge.size() == 0) cout << 0 << endl;
		else {
			for (int i = 1; i <= n; i++) {
				for (auto& h : adj[i])
					if (low[h] != low[i])	brightcnt[low[i]]++;
			}
			for (auto& i : brightcnt) {
				if (i.second == 1) con1++;
			}
			cout << con0 + (con1 + 1) / 2 << "\n";
		}
	}
	return 0;
}