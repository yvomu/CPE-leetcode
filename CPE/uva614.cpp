#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
bool findd = 0;
void visit(int ph,int pw,int gh,int gw,int s,vector<vector<int>>& maze,vector<vector<int>>& wall,vector<vector<int>>& dir) {
	maze[ph][pw] = s;
	s++;
	if (ph == gh && pw == gw) {
		findd = 1;
		return;
	}
			
	
	while (true) {
		if (findd == 1)
			return;
		if (dir[ph][pw] == 0) {
			if (maze[ph][pw-1] == 0) {
				if (wall[ph][pw - 1] == 0 || wall[ph][pw - 1] == 2)
				{
					dir[ph][pw] ++;
					visit(ph, pw-1, gh, gw, s, maze, wall, dir);
					continue;
				}
			}
			
		}
		else if (dir[ph][pw] == 1) {
			if (maze[ph - 1][pw] == 0) {
				if (wall[ph - 1][pw] == 0 || wall[ph - 1][pw] == 1)
				{
					dir[ph][pw] ++;
					visit(ph-1, pw, gh, gw, s, maze, wall, dir);
					continue;
				}
			}
		}
		else if (dir[ph][pw] == 2) {
			if (maze[ph][pw + 1] == 0) {
				if (wall[ph][pw] == 0 || wall[ph][pw] == 2)
				{
					dir[ph][pw] ++;
					visit(ph, pw+1, gh, gw, s, maze, wall, dir);
					continue;
				}
			}
			
		}
		else if (dir[ph][pw] == 3) {
			if (maze[ph + 1][pw] == 0) {
				if (wall[ph][pw] == 0 || wall[ph][pw] == 1)
				{
					dir[ph][pw] ++;
					visit(ph+1, pw, gh, gw, s, maze, wall, dir);
					continue;
				}
			}
			
		}
		else {
			maze[ph][pw] = -1;
			break;
		}
		dir[ph][pw] ++;
	}

}

int main() {
	int h,mazen = 0;
	while (cin >> h && h != 0) {
		mazen++;
		int w, sh, sw, gh, gw;
		cin >> w >> sh >> sw >> gh >> gw;
		vector<vector<int>> maze(h+2, vector<int>(w+2, 0));
		vector<vector<int>> wall(h+2, vector<int>(w+2, 3)); // ne ns=0,e = 1,s = 2,es = 3
		vector<vector<int>> dir(h+2, vector<int>(w+2, 0)); // 0 : <, 1 : ^, 2 : >, 3 : £¾
		for (int i = 0; i <= h+1; i++) {
			maze[i][0] = -1;
			maze[i][w+1] = -1;
		}
		for (int i = 0; i <= w+1; i++) {
			maze[0][i] = -1;
			maze[h+1][i] = -1;
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int wal;
				cin >> wall[i][j];
			}
		}
		/*maze[sh][sw] = 1;
		if (wall[sh][sw] == 0 || wall[sh][sw] == 2)
			sw++;
		else
			sh++;*/
		visit(sh, sw, gh, gw,1, maze, wall, dir);

		cout << "Maze " << mazen << endl<<endl;
		cout << "+";
		for (int i = 0; i < w; i++)
			cout << "---+";
		for (int j = 1; j <= h; j++) {
			cout << endl << "|";
			for (int i = 1; i <= w; i++) {
				if(maze[j][i] == -1 )
					cout << "???";
				else if (maze[j][i] == 0)
					cout << "   ";
				else
					cout<< setw(3) << maze[j][i];
				if (wall[j][i] == 1 || wall[j][i] == 3 || i == w)
					cout << "|";
				else
					cout << " ";
			}
			cout << endl << "+";
			for (int i = 1; i <= w; i++) {
				if (wall[j][i] == 2 || wall[j][i] == 3 || j == h)
					cout << "---+";
				else
					cout << "   +";
			}

		}
		
		cout << endl<<endl<<endl;
		findd = 0;
	}
	return 0;
}