#include <iostream>
#include "string"
struct uzel {
     long long int max;
     long long int chislo;
    uzel* predidyshii;
};

struct stack {
    uzel  *golova;
};

int mx(stack *s){
    if (s->golova->predidyshii== nullptr){
        s->golova->max=s->golova->chislo;
    }
    else{
        if(s->golova->chislo>s->golova->predidyshii->max){
            s->golova->max=s->golova->chislo;
        }
        else{
            s->golova->max=s->golova->predidyshii->max;
        }

    }
    return s->golova->max;
}


void add(stack  *s, long long int chislo) {
    uzel  *temp = new uzel;
    temp->chislo = chislo;
    temp->predidyshii = s->golova;
    s->golova = temp;
    mx(s);
}

void pop(stack* s) {

    s->golova = s->golova->predidyshii;
}





int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    stack* stak = new stack;
    stak->golova =nullptr;
    long long int amount_of_commands;
    std::cin >> amount_of_commands;


    for (int i = 0; i<amount_of_commands; i++) {
        std::string command;
        long long int number;
        std::cin >> command;
        if (command == "+") {
            std::cin >> number;
            add(stak, number);
        }
        else if (command == "-") {
            pop(stak);
        }
        else if (command == "max"){
            std::cout <<mx(stak)<<"\n";
        }
    }
}