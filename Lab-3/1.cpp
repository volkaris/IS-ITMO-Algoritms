#include <iostream>

struct node {
	
		int chislo;
		node* sledyishi;
	
};

struct ochered {
	
		node* golova;
		node* xvost;
	
};

void add(ochered* q, int chislo)
{
	node* n = new node;
	n->chislo = chislo;
	n->sledyishi = NULL;
	if (q->golova == NULL)
	{
		q->golova = n;
		q->xvost = n;
	}
	else
	{
		q->xvost->sledyishi = n;
		q->xvost = n;
	}
}


void pop(ochered* q) {

		
	std::cout <<q->golova->chislo <<"\n";
	node* n = q->golova;
	q->golova = q->golova->sledyishi;

}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	ochered* q = new ochered;
	q->golova = nullptr;
	q->xvost = nullptr;
	
	int amount_of_commands;
	std::cin >> amount_of_commands;


	for (int i = 0; i < amount_of_commands; i++) {
		char command;
		int number;
		std::cin >> command;
		if (command == '+') {
			std::cin >> number;
			add(q, number);
		}
		else if (command == '-') {
			pop(q);
		}
	}
}	

