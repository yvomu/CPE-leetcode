#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	int s;
	cin >> s;
	while (s--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> cost(m, vector<int>(n));
		vector<vector<int>> vis(m+1, vector<int>(n+1, 0));
		vector<vector<int>> formStoEcost(m, vector<int>(n, 99999));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> cost[i][j];

		priority_queue<pair<int, pair<int, int>>,  vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({ cost[0][0], { 0,0 } });
		formStoEcost[0][0] = cost[0][0];
		while (!pq.empty()) {
			pair<int, pair<int,int>> min = pq.top();
			pq.pop();
			
			vis[min.second.first][min.second.second] = 1;

			for (auto& i : dir) {
				int nextx = min.second.first+i[0];
				int nexty = min.second.second+i[1];
				if (nextx < 0 || nextx >= m || nexty<0 || nexty >= n || vis[nextx][nexty] == 1 )	continue;
				int nextval = min.first + cost[nextx][nexty];
				if (nextval < formStoEcost[nextx][nexty]) {
					formStoEcost[nextx][nexty] = nextval;
					pq.push({ nextval,{nextx,nexty } });
				}

			}
		}

		cout << formStoEcost[m-1][n-1]<<endl;
	}
	
	return 0;
}