#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <regex>
#include <sstream>
using namespace std;


std::regex name_regex("[A-Z][a-z]*");


std::regex age_regex("\\d{2}");

std::regex number_regex1(R"(\+7\(\d{3}\)\d{3}-\d{4})");
std::regex number_regex2(R"(\+7\d{3}\d{3}\d{4})");
std::regex number_regex3(R"([7]{1}\d{10})");
std::regex number_regex4(R"([78]\d{3}\d{3}\d{4})");
std::regex number_regex5(R"(\+7\(\d{3}\)\-\d{3}-\d{2}-\d{2})");

std::regex city_abr(R"(g\.[A-Z]{3},)");

std::regex street_regex4(R"(ul\.[A-Z]{1}\w*,)");

std::regex last_regex4(R"(d\.\d{2,})");

void valid(std::vector<std::string>& requests) {
	
	size_t pos = 0;
	if (requests.size() != 8) {
		cout << "NO\n";
		return;
	}

	if (regex_match(requests[0], name_regex) and regex_match(requests[1], name_regex) and regex_match(
		requests[2], name_regex) and
		regex_match(requests[3], age_regex) and (regex_match(requests[4], number_regex1) or
			regex_match(requests[4], number_regex2) or regex_match(requests[4], number_regex3) or
			regex_match(requests[4], number_regex4) or regex_match(requests[4], number_regex5)) and
		regex_match(requests[5], city_abr) and regex_match(requests[6], street_regex4) and regex_match(
			requests[7], last_regex4)) {
		cout << "YES\n";
		return;
	}

	else {
		cout << "NO\n";
		return;
	}
}


int main() {
	size_t lines;
	cin >> lines;
	cin.ignore();
	for (size_t i = 0; i < lines; ++i) {
		vector<string> input;
		std::string str;

		std::getline(std::cin, str);
		std::string tmp;
		stringstream ss(str);

		while (getline(ss,tmp, ' ')) {

			
			input.emplace_back(tmp);
		}

		valid(input);
		
	}

}
