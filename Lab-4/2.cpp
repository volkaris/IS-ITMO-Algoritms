using namespace std;
#include <iostream>

void siftup(int *arr, int size,int i) {
	int largest = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
        if (left_child<size and arr[left_child] > arr[largest])
        {
          largest = left_child;
        }
	if (right_child < size and arr[right_child] > arr[largest]) {
          largest = right_child;
        }
        if (largest!=i)
        {
          swap(arr[i], arr[largest]);
          siftup(arr, size, largest);
        }

}

void build_heap(int *arr, int size) {
  for (int i = (size-2) / 2; i >= 0; i--) {
    siftup(arr, size, i);
  }
}



void heap_sort(int *arr,int size) {
	build_heap(arr, size);
  for (int i=size-1;i>=1;i--)
  {
          swap(arr[i], arr[0]);
  	   //  size--;
          siftup(arr, i, 0);

  }

}

void print(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  // a[i]>=a[2i+1] && a[i]>=a[2i+2] for all i
  int n;
  cin >> n;
  auto arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  heap_sort(arr, n);
  print(arr, n);
}