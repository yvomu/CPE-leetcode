#include <iostream>
#include <string>

using namespace std;


int main() {
	string text = "acbaaa";
	int chars[26] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int begin = 0, end = 0, changes = -1, max = -1,lenth  = 0;

	while (1) {
		if (end == text.size()) {
			bool f = 0;
			if (changes != -1) {
				if (chars[text[begin] - 'a'] == -1)
					lenth--;
			}
			else {
				if (chars[text[begin] - 'a'] != -1)
					lenth++;
			}
				
			if (lenth > max)
				max = lenth;
			chars[text[begin] - 'a'] = begin;
			begin++;
			end = begin;
			changes = -1;
			lenth = 0;
		}
		
		if (begin == text.size() - 1) {
			if (1 > max)
				max = 1;
			break;
		}
			
		if (text[begin] == text[end] && end != text.size()) {
			lenth++;
			end++;
			continue;
		}
		else if(changes == -1){
			changes = end;
			lenth++;
			end++;
			continue;
			
		}
		else {
			bool f = 0;
			if (chars[text[begin] - 'a'] == -1) {
				while (end != text.size()) {
					end++;
					if (text[end] == text[begin]) {
						f = 1;
						break;
					}

				}
				if (f == 0)
					lenth = changes - begin;
			}
			if (lenth > max)
				max = lenth;
			chars[text[begin] - 'a'] = begin;
			begin++;
			end = begin;
			changes = -1;
			lenth = 0;
		}
		

	}
	cout << max;
	return 0;
}