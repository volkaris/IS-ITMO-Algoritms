#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> max_prefix(const std::string& str) {
	std::vector<size_t> answer(str.length(), 0);

	size_t i = 1;
	size_t j = 0;

	while (i != str.length()) {
		if (str[i] == str[j]) {
			answer[i] = j + 1;
			++i; ++j;
		}

		else {
			if (j == 0) {
				answer[i] = 0;
				++i;
			}

			else if (j != 0) {
				j = answer[j - 1];
			}
		}
	}

	return answer;
}

int main() {
	std::string str;
	std::cin >> str;

	std::vector<size_t> answer = max_prefix(str);

	for (decltype(auto) prefix : answer) {
		std::cout << prefix << " ";
	}
}
