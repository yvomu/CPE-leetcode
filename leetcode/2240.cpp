#include <iostream>

using namespace std;

int main() {
	int total = 1000000, cost1 = 1, cost2 = 1;
	long long way = 0;
	for (; total >= 0; total -= cost1) {
		way += total / cost2 + 1;
	}
	cout << way;
	return 0;
}