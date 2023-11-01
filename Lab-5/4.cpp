#include <iostream>

using namespace std;

class Node
{public:
    int x;
    Node* l, * r;
};

Node* insert(int x, Node*& tree)
{
    if (tree== nullptr)
    {
        tree = new Node;
        tree->x = x;
        tree->l = tree->r = nullptr;
    }
    if (x < tree->x)
    {
        tree->l = insert(x, tree->l);
    }
    if (x > tree->x)
    {
            tree->r = insert(x, tree->r);

    }
return tree;

}

bool exists(int x, Node* tree) {
    Node* node = tree;
    if (node == nullptr) {
        return false;
    }
    if (node->x == x) {
        return true;
    }
    if (node->x > x)
    {
        return exists(x, node->l);
    }
    else {
        return exists(x, node->r);
    }
}

void next(int x, Node* tree, int& n) {
    if (tree == nullptr) {
        return;
    }
    if (tree->x > x and n > tree->x) {
        n = tree->x;
    }
    next(x, tree->l, n);
    next(x, tree->r, n);
    return;
}

void prev(int x, Node* tree, int &n) {
    if (tree == nullptr) {
        return;
    }
    if (tree->x < x and n < tree->x) {
        n = tree->x;
    }
    prev(x, tree->l, n);
    prev(x, tree->r, n);
    return;
}

int successor(Node* tree) {
    tree = tree->r;
    while (tree->l != nullptr) {
    tree = tree->l;
    }
    return tree->x;
}
int predecessor(Node* tree) {
    tree = tree->l;
    while (tree->r != nullptr) {
        tree = tree->r;}
    return tree->x;
}

Node* deletenode(Node*& tree, int x) {
    if (tree == nullptr)
        return nullptr;
    if (x > tree->x)
        tree->r = deletenode(tree->r, x);
    else if (x < tree->x)
        tree->l = deletenode(tree->l, x);
    else {
        if (tree->l == nullptr and tree->r == nullptr)
            tree = nullptr;
        else if (tree->r != nullptr) {
            tree->x = successor(tree);
            tree->r = deletenode(tree->r, tree->x);
        }
        else {
            tree->x = predecessor(tree);
            tree->l = deletenode(tree->l, tree->x);
        }
    }
    return tree;
}

int main()
{
    Node* tree = nullptr;
    bool ex;
    int n, k;
    string s;
    while (cin >> s and cin >> k) {
        if (s == "insert") {
            insert(k, tree);
        }
        else if (s == "exists") {
            ex = exists(k, tree);
            if (ex) 
                cout << "true" << endl;
            else  
                cout << "false" << endl;
        }
        if (s == "next") {
            n = 1000000000;
            next(k, tree, n);
            if (n == 1000000000) 
                cout << "none" << endl;
            else  
                cout << n << endl;
        }
        if (s == "prev") {
            n = -1000000000;
            prev(k, tree, n);
            if (n == -1000000000) 
                cout << "none" << endl;
            else  
                cout << n << endl;
        }
        if (s == "delete") {
            deletenode(tree, k);
        }
    }
}
