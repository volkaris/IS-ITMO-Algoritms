#include <iostream>
#include <string>
#include <vector>


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t n, m, counter = 0;
	std::string song;
	std::cin >> n >> m >> song;

	for (size_t i = 0; i < m; ++i) {
		size_t first_start, second_start, lenght;

		std::cin >> first_start >> second_start >> lenght;
		--first_start;
		--second_start;

		std::string first;
		std::string second;

		for (int i=0;i<lenght;++i) {
			first += song[first_start+i];
			second += song[second_start + i];
		}

		if (first==second) {
			++counter;
		}
	  


	}


	std::cout << counter;
}
