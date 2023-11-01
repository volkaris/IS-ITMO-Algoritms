#include <iostream>
#include <algorithm>
#include "vector"
void merge(int array[], int const left, int const mid,
    int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
int main() {
using namespace std;
    int n;
    cin >> n;
  
    int a_0[100001];
    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        a_0[i] = g;
    }
    int m;
    cin >> m;
    int b_0[100001];
    for (int i = 0; i < m; i++) {
        int g;
        cin >> g;
        b_0[i] = g;
    }
    mergeSort(a_0, 0, n - 1);
    mergeSort(b_0, 0, m - 1);
   

    vector<int> a1;
    
    a1.push_back(a_0[0]);
    for (int i = 1; i < n; i++) {
        if (a_0[i] != a_0[i - 1]) {
            a1.push_back(a_0[i]);
        }
    }
  
    vector<int> b1;

    b1.push_back(b_0[0]);
    for (int i = 1; i < m; i++) {
        if (b_0[i] != b_0[i - 1]) {
            b1.push_back(b_0[i]);
        }
    }
    if (b1 == a1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}