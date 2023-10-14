#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> trace;
priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> bridge;
int dep = 0,n;

void dfs(int p,int now) {
	dep++;
	vis[now] = dep;
	trace[now] = now;
	for (auto& i : adj[now]) {
		if (vis[i]) {
			if (i != p )
				if (vis[i] < vis[trace[now]])
					trace[now] = i;
		}
		else {
			dfs(now, i);

			// 記錄第i點的子孫們用back edge連到的最高祖先
			if (vis[trace[i]] < vis[trace[now]])
				trace[now] = trace[i];

			// 子樹回不到祖先暨自身。
			if (vis[trace[i]] > vis[now])
				bridge.push({ min(now, i), max(now, i) });
		}
	}
}

int main() {
	
	while (cin >> n) {
		adj.assign(n, vector<int>());
		vis.assign(n, 0);
		trace.assign(n, -1);
		
		for (int i = 0; i < n; i++) {

			char t;
			int node, nodenum,node1;
			cin >> node >> t >> nodenum >> t;
			while (nodenum--)
			{
				cin >> node1;
				adj[node].push_back(node1);
			}
		}

		dep = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0)
				dfs(i,i);
		}
		int size = bridge.size();
		cout << size << " critical links\n";
		for (int i = 0; i < size; i++) {
			cout << bridge.top().first<<" - "<< bridge.top().second<<endl;
			bridge.pop();
		}
		cout << endl ;
	}
	return 0;
}