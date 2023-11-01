#include <iostream>
#include <sstream>
struct uzel {
	int chislo;
	uzel* predidyshii;
};

struct stack {
	uzel* golova;
};



void add(stack* s, int chislo) {
	uzel* temp = new uzel;
	temp->chislo = chislo;
	temp->predidyshii = s->golova;
	s->golova = temp;
}

int pop(stack* s) {
	int z = s->golova->chislo;
	s->golova = s->golova->predidyshii;
	return z;
}



int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	stack* stak = new stack;

	stak->golova = nullptr;
	std::string str;
	std::getline(std::cin, str);
	std::istringstream s(str);

	int value;
	char c;
	while (s.eof() == false)
	{
		s >> c;
		if (s.eof() == true) {
			break;
		}

		if (isdigit(c)) {
			add(stak, atoi(&c));
		}
		else {
			int val2 = pop(stak);
			int val1 = pop(stak);
			if (c == '+') {
				add(stak, val1 + val2);
			}
			else if (c == '-') {
				add(stak, val1 - val2);
			}
			else if (c == '*') {
				add(stak, val1 * val2);
			}

		}

	}
	std::cout << pop(stak);
}