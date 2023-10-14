#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(int n) {
    int r = 10;
    vector<int> v;
    if (n % 10 == 0)
        return false;
    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    for (int i = 0; i < v.size() / 2; i++) {
        if (v[i] != v[v.size() - 1 - i])
            return false;
    }
    return true;
}

bool isPrime_(int n) {
    int r = n-1;
    while (r > 1) {
        if (n % r == 0)
            return false;
        r--;
    }
    return true;
}
int backToInt(vector<int> v) {
    int r = 1, n = 0;
    for (int i = 0; i < v.size(); i++) {
        n += v[i] * r;
        r *= 10;
    }
    return n;
}
vector<int> nextPalindrome_v(vector<int> v) {
    vector<int> next = v;
    for (int i = next.size() / 2 - 1; i >= 0; i--) {
        next[i] = next[next.size() - 1 - i];
    }
    if ( backToInt(next) <= backToInt(v)) {
        int nine = 1;
        for (int i = 0; i < next.size(); i++) {
            if (next[i] != 9)
                nine = 0;
        }
        if (nine == 0) {
            next[next.size() / 2]++;
            if (next.size() % 2 == 0)
                next[next.size() / 2 - 1]++;

            if (next[next.size() / 2] > 9) {
                next[next.size() / 2 + 1]++;

                for (int i = next.size() / 2; i >= 0; i--) {
                    next[i] = 0;
                }
                return nextPalindrome_v(next);
            }
        }
        else {
            
            for (int i = 0; i < next.size(); i++) {
                next[i] = 0;
            }
            next.push_back(1);
            return nextPalindrome_v(next);
        }
        
    }
   
    return next;
    
}



vector<int> dissassamble(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }
    return v;
}

int nextPalindrome(int n) {
    vector<int> v = dissassamble(n);
    v = nextPalindrome_v(v);
    return backToInt(v);
}


bool isPrime(int num) {
    if (num < 2 || num % 2 == 0) return num == 2;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}
int primePalindrome(int N) {
    if (8 <= N && N <= 11) return 11;
    for (int x = 1; x < 100000; ++x) {
        string s = to_string(x), r(s.rbegin(), s.rend());
        int y = stoi(s + r.substr(1));
        cout << y << endl;
        if (y >= N && isPrime(y)) return y;
    }
    return -1;
}


int main() {
    int n;
    cin >> n;
    //while (1) {
    //    n = nextPalindrome(n);
    //    //cout << n << endl;
    //    if (isPrime(n)) {
    //        cout << n;
    //        break;
    //    }
    //    
    //    
    //}
    cout << primePalindrome(n);
    return 0;
}