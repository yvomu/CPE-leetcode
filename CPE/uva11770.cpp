#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <fstream>
using namespace std;

vector<unordered_set<int>> adj = { 100003,unordered_set<int>() };
int vis[10002] = { 0 };
int low[10002] = { 0 };
bool intstac[10002] = { 0 };
stack<int> st;
int group[10002] = { 0 };
int dep = 0;

void dfs(int p, int cur) {
	vis[cur] = low[cur] = ++dep;
	intstac[cur] = 1;
	st.push(cur);

	for (auto& i : adj[cur]) {
		if (!vis[i])	dfs(cur, i);
		if (intstac[i]) low[cur] = min(low[i], low[cur]);
	}

	if (low[cur] == vis[cur]) {
		int j;
		do {
			j = st.top();
			st.pop();
			intstac[j] = 0;
			group[j] = cur;
		} while (cur != j);
	}
}

int main() {
	fstream out("out.txt", ios::out);
	int casen, icase = 0;
	cin >> casen;
	while (casen--) {
		icase++;
		int n, m;
		cin >> n >> m;
		adj.assign(100003, unordered_set<int>());
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].insert(b);
		}
		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		memset(intstac, 0, sizeof(intstac));
		memset(group, 0, sizeof(group));
		dep = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				dfs(i, i);
		}
		int ingroup[10003] = { 0 };
		bool isgroup[10003] = { 0 };
		for (int i = 1; i <= n; i++) {
			isgroup[group[i]] = 1;
			for (auto& j : adj[i]) {
				if(group[i] != group[j])
				ingroup[group[j]]++;
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (ingroup[i] == 0 && isgroup[i])
				sum++;
		}
		cout <<"Case "<<icase<<": " << sum << endl;
		out << "Case " << icase << ": " << sum << endl;
	}
	return 0;
}