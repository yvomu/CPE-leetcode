#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = { 7,5,6,8,3 };
    sort(nums.begin(), nums.end());
    int min = nums[0], max = nums[nums.size() - 1];
    int i = min;
    for (i; i > 0; i--) {
        if (max % i == 0 && min % i == 0)
            break;
    }
    cout<< i;
	
}