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



	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string hymn, name;
	std::cin >> hymn >> name;

	

	std::vector<size_t> answer = max_prefix(name+"#"+hymn);

	std::vector<size_t> answer2;
	
	 
	size_t counter = 0;

	for (size_t i = name.length()+1; i < hymn.length()+ name.length()+1; ++i) {
		

		if (answer[i] == name.length()) {
			++counter;

			
			answer2.emplace_back( i - 2*name.length() );
		}
	}

	std::cout << counter << "\n";


	for (decltype(auto) prefix : answer2) {
		std::cout << prefix << " ";
	}
}
