#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

vector<vector<int>> adj = { 999001,vector<int>() };
int vis[2000] = { 0 };
int low[2000] = { 0 };
bool instack[2000] = { 0 };
map<string, int> namemap;
int dep = 0,groupsum = 0;
stack<int> st;

void dfs(int cur) {
	vis[cur] = low[cur] = ++dep;
	instack[cur] = true;
	st.push(cur);

	for (auto& i : adj[cur]) {
		if (!vis[i]) dfs(i);
		if (instack[i]) low[cur] = min(low[cur], low[i]);
	}

	if (low[cur] == vis[cur]) {
		groupsum++;
		int j;
		do {
			j = st.top();
			instack[j] = 0;
			st.pop();
		} while (j != cur);
	}

}


int main() {
	int p, t;
	fstream out("out.txt", ios::out);
	while (cin >> p >> t && p) {
		adj.assign(999001, vector<int>());
		namemap.clear();
		cin.get();
		string name, name1,str;
		for (int i = 0; i < p; i++) {
			getline(cin, name);
			namemap[name] = i;
		}
		for (int i = 0; i < t; i++) {
			getline(cin, name);
			getline(cin, name1);
			adj[namemap[name]].push_back(namemap[name1]);
		}

		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		memset(instack, 0, sizeof(instack));
		
		groupsum = 0;
		dep = 0;
		for (int i = 0; i < p; i++) {
			if (!vis[i])
				dfs(i);
		}
		cout << groupsum << endl;
		out << groupsum << endl;
	}
	return 0;
}