#include <iostream>
#include <vector>

using namespace std;
const int mod = 1000000007;
int main() {
    int low, high, zero, one;
    cin >> low >> high >> zero >> one;

    int ans = 0;

    vector<int> f(high + 1, 0);
    f[0] = 1;

    for (int i = 1; i <= high; i++) {
        if (i == zero && i == one) {
            f[i] = 2;
            continue;
        }
        if (i < zero && i < one)
            f[i] = 0;
        else if (i >= zero && i < one )
            f[i] = f[i-zero];
        else if(i < zero && i >= one)
            f[i] = f[i - one];
        else
            f[i] = (f[i - zero] + f[i - one]) % mod;
    }

    for (int i = low; i <= high; i++) {
        ans = (f[i] + ans) % mod;
    }
    cout << ans;
    

}