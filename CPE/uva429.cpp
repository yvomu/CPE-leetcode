#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;
vector<vector<int>> adj = { 50000,vector<int>() };
int vis[205] = { 0 };
int dep[205] = { 0 };
unordered_map<string, int> dic;
string dic2[205] = { "" };
int cnt = 0;

string beg, endd;

void dfs() {
    queue<int> q;
    q.push(dic[beg]);
    //dep[beg] = 0;
    while (!q.empty()) {
        int size = q.size();

        while (size--){
            int cur = q.front();
            q.pop();
            if (dic2[cur] == endd)    return;
            vis[cur] = 1;
        
            for (auto& i : adj[cur]) {
                if (!vis[i]) {
                    q.push(i);
                   // dep[i] = dep[cur] + 1;
                }
                
            }
           }
        cnt++;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string t;
    getline(cin, t);
    while (n--) {
        adj.assign(50000, vector<int>());
        dic.clear();
        //memset(dic2,2,sizeof(dic2));
        
        int wcnt = 0;
        while (getline(cin, t) && t != "*")  dic[t] = wcnt,dic2[wcnt++] = t;
        
        for (int i = 0; i < wcnt; i++) for (int j = i + 1; j < wcnt; j++) {
                if (dic2[i].size() != dic2[j].size())    continue;
               
                int dif = 0;
                for (int k = 0; k < dic2[i].size(); k++) {
                    if (dic2[i][k] != dic2[j][k]) dif++;
                }
                
                if (dif == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

                
            
        }
        
        
        
        
        while (getline(cin, t) && !t.empty()) {
            
            stringstream ss(t);
            ss >> beg >> endd;
            cnt = 0;
            memset(vis, 0, sizeof(vis));
            //memset(dep, 0, sizeof(dep));
            dfs();
            cout << beg <<" "<< endd<<" " << cnt << endl;
        }
        if (n) cout << '\n';
    }

    return 0;
}
