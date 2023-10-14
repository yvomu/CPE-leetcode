#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int>> adj;
vector<int> vis, low;
vector<bool> cut;
int dep;
stack<pair<int,int>> s;
vector<unordered_set<int>> bcc;

void dfs(int p, int cur) {
	vis[cur] = low[cur] = dep++;
	int child = 0;

	for (auto& i : adj[cur]) {
		if (vis[i] != -1) {
			if (i != p)
				low[cur] = min(low[cur], vis[i]);
		}
		else {
			child++;
			s.push({ i, cur });
			dfs(cur, i);

			low[cur] = min(low[i], low[cur]);
			if (low[i] >= vis[cur]) {
				cut[cur] = true;
				unordered_set<int> t;
				while (1) {
					int a = s.top().first, b = s.top().second;
					s.pop();
					t.insert(a);
					t.insert(b);
					if (a == i && b == cur) break;
				}
				bcc.push_back(t);
			}

		}
	}
	if (p == cur && child == 1) cut[cur] = false;
}

int main() {
	int n,cas = 1;
	while (cin >> n && n) {
		
		adj.assign(n+2, vector<int>());
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		vis.assign(n + 2, -1), low.assign(n + 2, -1);
		cut.assign(n + 2, false);/*
		memset(vis, -1, sizeof(vis));
		memset(low, -1, sizeof(low));
		memset(cut, false, sizeof(cut));*/
		dep = 0;
		bcc.clear();
		dfs(1, 1);
		long long ans1 = 0, ans2 = 1;
		if (bcc.size() == 1)	ans1 = 2, ans2 = bcc[0].size() * (bcc[0].size() - 1)/2;
		else {
			for (auto& i : bcc) {
				int cmt = 0;
				for (auto& j : i) {
					if (cut[j] == 1)
						cmt++;
				}
				if (cmt == 1) ans1++, ans2 *= i.size() - 1;
			}
		}
		cout <<"Case "<<cas<<": " << ans1 << " " << ans2 << endl;
		cas++;
	}
	return 0;
}