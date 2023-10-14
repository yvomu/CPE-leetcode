#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> prices = { 1,2,3,0,2 };
	int size = prices.size();
	vector<int> s0( size ,0 );
	vector<int> s1(size, 0);
	vector<int> s2(size, 0);

	s0[0] = 0;
	s1[0] = 0 - prices[0];
	s2[0] = INT_MIN;

	for (int i = 1; i < prices.size(); i++) {
		s0[i] = max(s0[i - 1], s2[i - 1]);
		s1[i] = max(s0[i - 1] - prices[i], s1[i - 1]);
		s2[i] = s1[i - 1] + prices[i];
	}

	int max_ = INT_MIN;
	max_ = max(s0[size - 1], s1[size - 1]);
	max_ = max(max_, s2[size - 1]);
	cout << max_;
	return 0;
}