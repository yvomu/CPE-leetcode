#include <iostream>
#include <vector>
#include <functional>
#include <climits>
using namespace std;


int visit(int i, vector<int> &emailmap, vector<bool> &sended, vector<bool> &emailmapv) {
	
	if (sended[i] == 1)		return 0;
	else {
		
		sended[i] = emailmapv[i] = 1;
		return 1+visit(emailmap[i], emailmap, sended, emailmapv);
	}
}

int main() {
	int casenum,casen = 0;
	cin >> casenum;
	while (++casen <= casenum) {
		int nodenum;
		cin >> nodenum;
		vector<int> emailmap(nodenum+1, 0);
		int maxM = 0, maxp = INT_MIN;
		vector<bool> emailmapv(nodenum + 1, 0), sended;
		for (int i = 0; i < nodenum; i++) {
			int from, to;
			cin >> from >> to;
			emailmap[from] = to;
		}
		
		

		//function<int(int)> visit = [&](int u) -> int
		//{
		//	// 如果已經寄過了就直接回傳，避免環
		//	if (sended[u]) return 0;
		//	sended[u] = emailmapv[u] = true;
		//	return 1 + visit(emailmap[u]);
		//};

		for (int i = 1; i <= nodenum; i++) {
			if (emailmapv[i] == 1)
				continue;
			sended.assign(nodenum + 1, false);

			int time = visit(i, emailmap, sended, emailmapv);
			if (time > maxp)	maxp = time,maxM = i;
			

		}
		cout << "Case "<<casen<<": " << maxM << endl;
	}
	return 0;
}