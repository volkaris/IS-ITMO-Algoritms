#include <iostream>
#include <string>

struct Node {
    char key;
    Node *prev = nullptr;   //нуллптр новое
};

struct Stack {
    Node *head = nullptr;   //нуллптр новое
};


void add(Stack *s, char chislo) {
    Node* temp = new Node;
    temp->key = chislo;
    temp->prev = s->head;
    s->head = temp;
    //std::cout << s->golova->chislo;

}

char pop(Stack* s) {
    char z = s->head->key;
    s->head = s->head->prev;
    return z;
}


bool IsEmpty(Stack *s) {
    if (s->head == nullptr)
        return true;
    else
        return false;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    char sym;
    std::string sym2;
    while (std::cin >> sym2) {
        bool correct = true;
        Stack* stack = new Stack;
        for (char i : sym2) {
            sym = i;

            if (sym == '(' or sym == '[') {
                add(stack, sym);
            }
            if (sym == ')' or sym == ']') {    //если зашли сюда,то подана закрывающая скобка
                char prev_c;
                if (!IsEmpty(stack)) {
                    prev_c = pop(stack);
                } else {    //если оказались здесь,то у нас первым элементом идет закрывающая скобка,мы не добавляем ее в стек,а сразу считаем,что это неправильно,т.к сначала идет открывающая скобка,а потом закрывающая
                    correct = false;
                    break;
                }
                if ((sym == ')' and prev_c != '(') or (sym == ']' and prev_c != '[')) {
                    correct = false;
                    break;
                }
            }
        }

        if (correct and IsEmpty(stack)) {
            std::cout << "YES\n";
        } else
            std::cout << "NO\n";
        
    }
}
