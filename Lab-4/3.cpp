#include <iostream>
#include <string>
#include <vector>

using namespace std;
void siftUp( int current, vector<int>& arr);

void push(int key, vector<int>& arr,  int cur_size) {  
  arr[cur_size] = key;
  siftUp(cur_size, arr);
}

void siftUp( int current,vector<int>& arr) {  
 
  if (current > 0 and arr[current] < arr[(current - 1) / 2]) {
    swap(arr[current], arr[(current - 1) / 2]);
    siftUp((current - 1) / 2, arr);
  }
}

void siftdown(vector<int>& arr, int size,int i) {  
  int largest = i;
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;
  if (left_child < size and arr[left_child] < arr[largest]) {
    largest = left_child;
  }
  if (right_child < size and arr[right_child] < arr[largest]) {
    largest = right_child;
  }
  if (largest != i and arr[largest] != 0) {
    swap(arr[i], arr[largest]);
    siftdown(arr, size, largest);
  }
}

int extractMin(vector<int>& arr, int curIndex) {
 
  if (curIndex > 0) {
    int result = arr[0];
    swap(arr[0], arr[curIndex - 1]);
    siftdown(arr, curIndex-1, 0);
    return result;
  }
  return -1000000001;
}

void decrease_key(vector<int>& arr, int x, int y, int cur_size) {
  int actualIndex = INT_MIN;
  for (int i = 0; i < cur_size; i++) {
    if (arr[i] == x) {
      actualIndex = i;
      goto end;
    }
  }
  end:
  arr[actualIndex] = y;
  siftUp(actualIndex, arr);
}

int main() {
  static int cur_size = 0;
  vector<int> numbers_by_order(1000000);    
  vector<int> numbers_in_queue(1000000);  
  int count = 0;
  string command;
  while (cin >> command) {
    int number;
    if (command == "push") {
      cin >> number;
      numbers_by_order[count] = number;
      push(number, numbers_in_queue, cur_size);
     cur_size++;
    }
    
    else if (command == "extract-min") {
      int h = extractMin(numbers_in_queue, cur_size);
      cur_size--;
      if (h != -1000000001) {
        cout << h << "\n";
      } else {
        cur_size = 0;
        cout << "*\n";
      }
    }
    
    
    else if (command == "decrease-key") {
      int x, y;
      cin >> x >> y;
      decrease_key(numbers_in_queue, numbers_by_order[x - 1], y, cur_size);
      numbers_by_order[x - 1] = y;
	
    }
    count++;
  }
}