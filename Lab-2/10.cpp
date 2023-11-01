#include <iostream>
#include "vector"
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
int main()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 2; i < n; i++) {
        swap(arr[i], arr[i / 2]);

    }


    for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }
}