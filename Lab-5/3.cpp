#include <iostream>

using namespace std;

struct node
{
    int info;
    node* left, * right;
};

int* b;

int findNextNum(node* tree, int n) {
    if (tree->right != nullptr) {
        n = findNextNum(tree->right, n);
    }
    b[(tree->info  - 1)] = n;
    n--;
    if (tree->left != nullptr) {
        n = findNextNum(tree->left, n);
    }
    else {
        tree = nullptr;
    }
    return n;
}

int main() {
    node* tree = nullptr;
    int n = 0, lc, rc, k;
    cin >> n;
    int i = 0;
    node** list = new node * [n];
    while (i < n) {
        list[i] = new node;
        list[i]->info =  (i + 1);
        list[i]->left = nullptr;
        list[i]->right = nullptr;
        i++;
    }
    b = new int[n];
    i = 0;
    while (i < n) {
        cin >> lc >> rc;
        if (lc == 0)
        {
            list[i]->left = nullptr;
        }
        else
        {
            list[i]->left = list[lc - 1];
        }
        if (rc == 0)
        {
            list[i]->right = nullptr;
        }
        else
        {
            list[i]->right = list[rc - 1];
        }
        b[i] = 0;
        i++;
    }
    findNextNum(list[0], n);
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    delete[] b;
}