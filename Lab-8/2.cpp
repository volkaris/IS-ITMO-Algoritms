#include <iostream>
#include <string>
#include <vector>
using namespace std;
int find_mistake(const std::string& hamming_code) {
	int error_index = 0;
	for (int i = 0; i < hamming_code.length(); i++) {
		if (hamming_code[i] == '1') {
		error_index =error_index^(i +1);
		}
	}

	return error_index;
}

void fix(string& str, int mistake) {
	if (str[mistake - 1] == '0') {
		str[mistake - 1] = '1';
	} else {
		str[mistake - 1] = '0';
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	size_t amount;
	cin >> amount;
	vector<string> result;
	for (size_t i = 0; i < amount; i++) {
		string str;
		string str1;
		cin >> str;
		size_t mistake = find_mistake(str);
		if (mistake) {
			fix(str, mistake);
		}

		for (size_t w = 0; w < str.size(); w++) {
			if ((w + 1) & (w)) {
				str1 += str[w];
			}
		}
		result.emplace_back(str1);
	}


	for (const auto& i : result) {
		cout << i << "\n";
	}

}
