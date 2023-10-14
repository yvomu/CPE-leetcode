#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

int main() {
	string sentence = "I speak Goat Latin";
	string in;
	string out;
	istringstream sen(sentence);
	int i = 0,j;
	while (sen >> in) {
		if (in[0] == 'a' || in[0] == 'e' || in[0] == 'i' || in[0] == 'o' || in[0] == 'u' || in[0] == 'A' || in[0] == 'E' || in[0] == 'I' || in[0] == 'O' || in[0] == 'U') {
			
		}
		else {
			in += in[0];
			
			in = in.substr(1);
		}
		out = out + in + "ma";
		for ( j = 0,++i; j < i; j++) {
			out += "a";
		}
		out += " ";
	}
	
	cout << out;
	return 0;
}