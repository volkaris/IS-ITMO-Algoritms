#include <iostream>
struct uzel { 
	int chislo;	
	uzel* predidyshii;	
};

struct stack {
	uzel  *golova;		
};



void add(stack  *s, int chislo) {
	uzel  *temp = new uzel;
	temp->chislo = chislo;
	temp->predidyshii = s->golova;
	s->golova = temp;
}

void pop(stack* s) {
	std::cout << s->golova->chislo<<"\n";
	s->golova = s->golova->predidyshii;		
}



int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	stack* stak = new stack;  
	stak->golova =nullptr;		  
	int amount_of_commands;	
	std::cin >> amount_of_commands; 


	for (int i = 0; i<amount_of_commands; i++) { 
		char command;
		int number; 
		std::cin >> command; 
		if (command == '+') { 
			std::cin >> number;	
			add(stak, number); 
		}
		else if (command == '-') {
			pop(stak);
		}
	}

}