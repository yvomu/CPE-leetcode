#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> adj = { 10000,vector<int>() };
vector<int> camcity;
map<string,int> citynum;
int vis[150] = {-1};
int trace[150] = {-1};
int cnt = 0;
int dep = 0;

void dfs(int p,int cur) {
	vis[cur] = dep++;
	trace[cur] = cur;
	bool ap = false;
	int child = 0;
	for (auto& i : adj[cur]) {
		if (vis[i] != -1) {
			if (i != p) {
				if (vis[i] < vis[trace[cur]])
					trace[cur] = i;
			}
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
	if ((cur == p && child > 1) || (cur != p && ap)){

		cnt++;
		camcity.push_back(cur);
	}
}

int main() {
	int n,cas = 0;
	
	while (cin >> n && n) {
		cas++;
		citynum.clear();
		adj.assign(10000, vector<int>());
		for (int i = 0; i < n; i++) {
			string c;
			cin >> c;
			citynum[c] = i;
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			string ca, cb;
			cin >> ca >> cb;
			adj[citynum[ca]].push_back(citynum[cb]);
			adj[citynum[cb]].push_back(citynum[ca]);
		}
		memset(vis, -1, sizeof(vis));
		memset(trace, -1, sizeof(trace));
		cnt = 0;
		camcity.clear();
		for (int i = 0; i < n; i++) {
			if(vis[i] == -1)
				dfs(i,i);
		}
		if(cas != 1)	cout << endl;
		vector<string> ordercity;
		cout << "City map #" << cas << ": " << cnt << " camera(s) found\n";
		for (auto& i : camcity) {
			for (auto& j : citynum)
				if (j.second == i)
					ordercity.push_back(j.first);
		}
		sort(ordercity.begin(), ordercity.end());
		for (auto& i : ordercity)
			cout << i << endl;
		
			
	}
	return 0;
}