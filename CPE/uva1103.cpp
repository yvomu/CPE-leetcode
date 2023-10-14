#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int w, h;
int img[205][205] = {0},vis[205][205] = { 0 };
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int cirnum = 0;
map<int, char> d = { {0,'W'},{1,'A'},{2,'K'},{3,'J'},{4,'S'},{5,'D'}};
void hextobi(string str,int pos) {
	for (int i = 0; i < str.size(); i++) {
		int t;
		t = (str[i] >= '0' && str[i] <= '9') ? str[i] - '0' : str[i] - 'a' + 10;
		for (int j = 0; j < 4; j++) {
			img[pos][i * 4 + j] = (t & 8 >> j) ? 1 : 0;
		}
			
	}
}

void bfs(pair<int, int> begin,int color,int sol) {
	queue<pair<int, int>> q;
	q.push(begin);
	vis[begin.second][begin.first] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next;
			next.first = cur.first + dir[i][0];
			next.second = cur.second + dir[i][1];
			if (next.first < 0 || next.first > (w+2)*4 || next.second < 0 || next.second > h + 1 || vis[next.second][next.first] == 1)	continue;
			if (sol == 1 && img[next.second][next.first] == 0) {
				cirnum++;
				bfs(next, 0, 0);
			}
			if (img[next.second][next.first] != color)	continue;
			vis[next.second][next.first] = 1;
			q.push(next);
		}
	}
}

int main() {
	int casen = 0;
	while (cin >> h >> w && h && w) {
		casen++;
		memset(img, 0, sizeof(img));
		memset(vis, 0, sizeof(vis));
		string str,ans;
		getchar();
		for (int i = 1; i <= h; i++) {
			getline(cin, str);
			str.insert(str.begin(), '0');
			str += '0';
			hextobi(str,i);
		}
		bfs({ 0, 0 }, 0, 0);
		for (int i = 1; i <= h; i++) {
			for (int j = 4; j <= (w+1)*4; j++){
				if (img[i][j] == 1 && vis[i][j] == 0) {
					cirnum = 0;
					bfs({ j,i }, 1, 1);
					ans += d[cirnum];
				}
					
			}
		}
		sort(ans.begin(), ans.end());
		cout <<"Case "<<casen<<": " << ans<<endl;
	}
	return 0;
}