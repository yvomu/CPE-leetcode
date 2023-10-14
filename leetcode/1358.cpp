#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "aaacb";
	int abc[3] = { 0,0,0 };
	int b = 0, e = 0,sum = 0;
	abc[str[0] - 'a'] ++;
	while (1) {
		
		if (abc[0] > 0 && abc[1] > 0 && abc[2] > 0) {
			sum += str.size() - e;
			abc[str[b] - 'a'] --;
			b++;
			
		}
			
		else {
			if (e == str.size()-1)
				break;
			e++;
			abc[str[e] - 'a'] ++;
			
			
		}
		
	}
	cout << sum;
	return 0;
}