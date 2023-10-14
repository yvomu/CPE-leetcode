#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include<fstream>
using namespace std;

vector<vector<int>> adj = { 6250000,vector<int>() };
bool vis[2505] = { 0 };
int mdbs = 0, fbd = 0;


void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	vis[cur] = 1;
	int f = 0;
	while (!q.empty()) {
		int s = q.size();
		int b = 0;
		f++;
		while (s--){
			
			int d = q.front();
			q.pop();
			
			for (auto& i : adj[d]) {
				if (!vis[i]) {
					vis[i] = 1;
					q.push(i);
					b++;
				}
			}
		}
		if (b > mdbs) {
			mdbs = b;
			fbd = f;
		}
	}
}

int main() {
	int E;
	while (cin >> E) {
		adj.assign(6250000, vector<int>());
		for (int i = 0; i < E; i++) {
			int n;
			cin >> n;
			for (int j = 0; j < n; j++) {
				int a;
				cin >> a;
				adj[i].push_back(a);
			}
		}
		
		fstream out("test.txt", ios::out);
		int T;
		cin >> T;
		while (T--) {
			mdbs = 0, fbd = 0;
			memset(vis, 0, sizeof(vis));
			int a;
			cin >> a;
			bfs(a);
			if (mdbs == 0) {
				cout << mdbs << endl;
				out << mdbs << endl;
			}
			else {
				cout << mdbs << " " << fbd << endl;
				out << mdbs << " " << fbd << endl;
			}
				
		}
	}
	return 0;
}