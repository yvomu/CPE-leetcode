#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> hash;
    vector<int>  candidates = { 8,8 };
    for (int i = 0; i < candidates.size(); i++) {
        int j = 0, candi = candidates[i];
        while (candi > 0) {
            int n = candi % 2;
            if (hash.size() == j) {
                vector<int> t;
                hash.push_back(t);
            }
            if(n == 1)
                hash[j].push_back(candidates[i]);
            candi /= 2;
            j++;
        }
    }

    int max = 0;
    for (int i = 0; i < hash.size(); i++) {
        if (hash[i].size() > max)
            max = hash[i].size();
    }
    cout << max;
	return 0;
}