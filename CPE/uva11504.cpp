#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <fstream>
using namespace std;

vector<vector<int>> adj = { 100010,vector<int>() };
int vis[100010] = { 0 };
int low[100010] = { 0 };
bool instack[100010] = { 0 };
int belongscc[100010] = { 0 };
int inedge[100010] = { 0 };
int dep;
stack<int> st;
unordered_set<int> sccnum;

void dfs(int p, int cur) {
	vis[cur] = low[cur] = ++dep;
	st.push(cur);
	instack[cur] = true;
	for (auto& i : adj[cur]) {
		if (!vis[i])
			dfs(cur, i);
		if (instack[i])
			low[cur] = min(low[i], low[cur]);
	}

	if (low[cur] == vis[cur]) {
		int j;
		do {
			j = st.top();
			st.pop();
			instack[j] = false;
			belongscc[j] = cur;
		} while (j != cur);
	}
}

int main() {
	int casen;
	cin >> casen;
	//ofstream out("out.txt", ios::out);
	while (casen--) {
		adj.assign(100010, vector<int>());
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}

		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		memset(belongscc, 0, sizeof(belongscc));
		memset(inedge, 0, sizeof(inedge));
		sccnum.clear();
		dep = 0;
		for (int i = 1; i <= n; i++) {
			if(!vis[i])
				dfs(i, i);
		}

		
		for (int i = 1; i <= n; i++) {
			sccnum.insert(belongscc[i]);
			for (auto& j : adj[i]) {
				if (belongscc[j] != belongscc[i])
					inedge[belongscc[j]]++;
			}
		}
		
		

		int sum = 0;
		for (auto& i : sccnum) {
			if (inedge[i] == 0)	sum++;
		}
		cout << sum<<endl;
		//out << sum<<endl;
	}
	return 0;
}