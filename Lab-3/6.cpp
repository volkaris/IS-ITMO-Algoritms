
#include <iostream>
using namespace std;

int left_bound(int* arr, int key, int size)
{
    int left = -1;
    int  right = size;
    while (right != left+1) {
        int middle = (left + right) / 2;
        if (arr[middle] < key) {
            left = middle;
        }
        else {
            right = middle;
        }
    }

     if (arr[right] != key) {
        return -1;
    }
    return right + 1;


}

int right_bound(int* arr, int key, int size)
{
    int left = -1;
    int  right = size;
    while (right!=left+1) {
        int middle = (left + right) / 2;
        if (arr[middle] <= key) {
            left = middle;
        }
        else {
            right = middle;
        }
    }
 
     if (arr[left] != key) {
        return -1;
    }
    return left + 1;

}



int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int zapros;
    cin >> zapros;

    for (int i = 0; i < zapros; i++)
    {
        int zapros_2;
        cin >> zapros_2;
        if (left_bound(arr, zapros_2, n) - right_bound(arr, zapros_2, n)==1) {
            cout << "-1 -1";

        }
        else { cout << left_bound(arr, zapros_2, n) << " " << right_bound(arr, zapros_2, n) << endl; }
    }
    delete[]arr;
}


