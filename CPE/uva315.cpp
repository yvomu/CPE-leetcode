#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;
int cnt = 0;
vector<vector<int>> adj = { 10000,vector<int>() };
vector<pair<int, int>> bridge;

int vis[1000] = { -1 }, trace[1000] = { -1 };
int dep = 0;

void dfs(int p, int cur) {
	vis[cur] = dep++;
	trace[cur] = cur;
	bool ap = false;
	int child = 0;
	for (auto& i : adj[cur]) {
		if (vis[i] != -1) {
			if(i != p)
				if (vis[i] < vis[trace[cur]])
					trace[cur] = i;
		}
		else {
			child++;
			dfs(cur, i);

			if (vis[trace[i]] < vis[trace[cur]])
				trace[cur] = trace[i];

			if (vis[trace[i]] >= vis[cur])
				ap = true;
		}
	}
	if (ap && ( child > 1 || cur != p))
		cnt++;
}

int main() {
	int n;
	while (cin >> n && n) {
		adj.assign(10000, vector<int>());
		memset(vis, -1, sizeof(vis));
		memset(trace, -1, sizeof(trace));
		dep = 0;
		cnt = 0;
		getchar();
		string str;
		while (getline(cin,str)) {
			int a, b;
			stringstream ss(str);
			ss >> a;
			if (a == 0)
				break;
			while (ss >> b)	adj[a].push_back(b), adj[b].push_back(a);
			
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i] == -1) {
				dfs(i, i);
			}
		}

		cout << cnt << endl;
	}
	return 0;
}